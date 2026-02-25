import math

# --- DANE I KONFIGURACJA ---
g_b = 1015  # hPa
g_t_s = [22.5, 21.8, 21.4, 21.8, 21.6]
g_t_m = [17, 18.2, 17.8, 17.8, 18.2]
g_w_3 = 35
g_w_4 = 30.5
dokladnosc_termometru = 0.1
dokladnosc_barometru = 1 * 0.75  # przeliczone na mmHg dla niepewności odczytu

tabela_p = {
    16: 13.63, 17: 14.53, 18: 15.48, 19: 16.48,
    20: 17.54, 21: 18.65, 22: 19.83, 23: 21.07
}

tabela_w_2 = {
    (17, 22.5): 58, (18.2, 21.8): 69, (17.8, 21.4): 71,
    (17.8, 21.8): 68, (18.2, 21.6): 72
}


def interpolacja(t_val):
    t = float(t_val)
    if t.is_integer():
        ti = int(t)
        p = tabela_p.get(ti)
        p_prev = tabela_p.get(ti-1, p-0.9)
        p_next = tabela_p.get(ti+1, p+0.9)
        delta = max(abs(p - p_prev), abs(p_next - p)) / 2
        return p, delta, f"Wartość z tabeli dla $t={ti}$"
    else:
        t1 = int(t)
        t2 = t1 + 1
        p1 = tabela_p.get(t1)
        p2 = tabela_p.get(t2)
        p = p1 + (p2 - p1) * (t - t1)
        delta = (p2 - p1) / 2
        opis = f"Interpolacja między {t1}°C ({p1}) a {t2}°C ({p2})"
        return p, delta, opis


def get_u_instr(dokladnosc):
    return dokladnosc / math.sqrt(3)


if __name__ == "__main__":
    # Stałe globalne do obliczeń
    b_hpa = g_b
    b_mmhg = g_b * 0.75
    # tu wchodzi juz przeliczona dokladnosc
    u_b_mmhg = get_u_instr(dokladnosc_barometru)
    u_t = get_u_instr(dokladnosc_termometru)

    # Listy na wyniki
    results_w1 = []
    results_u_B = []

    with open("pelne_obliczenia_obsidian.md", "w", encoding="utf-8") as f:

        f.write("# Szczegółowe Obliczenia Wilgotności\n\n")

        # 1. Dane wstępne
        f.write("## 1. Dane wstępne i niepewności przyrządów\n")
        f.write(
            f"- Ciśnienie atmosferyczne: $b = {b_hpa} \\text{{ hPa}} = {b_mmhg:.2f} \\text{{ mmHg}}$\n")
        f.write(f"- Niepewność standardowa termometrów: $$u(t) = \\frac{{{
                dokladnosc_termometru}}}{{\\sqrt{{3}}}} = {u_t:.4f} \\, ^\\circ\\text{{C}}$$\n")
        f.write(f"- Niepewność standardowa barometru (w mmHg): $$u(b) = \\frac{{{
                dokladnosc_barometru:.2f}}}{{\\sqrt{{3}}}} = {u_b_mmhg:.4f} \\text{{ mmHg}}$$\n\n")

        # 2. Pętla przez pomiary
        f.write("## 2. Obliczenia krok po kroku dla każdego pomiaru\n")

        for i, (tm, ts) in enumerate(zip(g_t_m, g_t_s)):
            nr = i + 1
            f.write(f"### Pomiar nr {nr}\n")
            f.write(f"Dane: $t_m = {tm}^\\circ\\text{{C}}$, $t_s = {
                    ts}^\\circ\\text{{C}}$\n\n")

            # A. Prężności nasycone
            pm, delta_pm, opis_m = interpolacja(tm)
            u_pm = delta_pm / math.sqrt(3)

            p0, delta_p0, opis_s = interpolacja(ts)
            u_p0 = delta_p0 / math.sqrt(3)

            f.write("**A. Wyznaczenie prężności pary nasyconej:**\n")
            f.write(f"- Dla termometru mokrego ($t_m={tm}$): {opis_m}.\n")
            f.write(f"  $$p_m = {pm:.2f} \\text{{ mmHg}}$$\n")
            f.write(f"  Niepewność odczytu (interpolacji): $\\Delta p_m = {
                    delta_pm:.3f}$.\n")
            f.write(f"  $$u(p_m) = \\frac{{{delta_pm:.3f}}}{{\\sqrt{{3}}}} = {
                    u_pm:.4f} \\text{{ mmHg}}$$\n")

            f.write(f"- Dla termometru suchego ($t_s={ts}$): {opis_s}.\n")
            f.write(f"  $$p_0 = {p0:.2f} \\text{{ mmHg}}$$\n")
            f.write(f"  $$u(p_0) = \\frac{{{delta_p0:.3f}}}{{\\sqrt{{3}}}} = {
                    u_p0:.4f} \\text{{ mmHg}}$$\n\n")

            # B. Prężność nienasycona p
            # p = pm - 0.5 * (ts - tm) * (b / 755)
            czlon_psychro = 0.5 * (ts - tm) * (b_mmhg / 755)
            p_val = pm - czlon_psychro

            f.write("**B. Obliczenie prężności pary nienasyconej $p$:**\n")
            f.write(
                "Wzór: $$p = p_m - 0.5 \\cdot (t_s - t_m) \\cdot \\frac{b}{755}$$\n")
            f.write("Podstawienie:\n")
            f.write(f"$$p = {
                    pm:.2f} - 0.5 \\cdot ({ts} - {tm}) \\cdot \\frac{{{b_mmhg:.1f}}}{{755}}$$\n")
            f.write(f"$$p = {
                    pm:.2f} - {czlon_psychro:.4f} = \\mathbf{{{p_val:.2f} \\text{{ mmHg}}}}$$\n\n")

            # C. Niepewność u(p)
            # Składniki pod pierwiastkiem
            A = 0.5 * (b_mmhg / 755)
            B = 0.5 * (ts - tm) / 755

            comp_pm = u_pm**2
            comp_ts = (A * u_t)**2
            comp_tm = (A * u_t)**2
            comp_b = (B * u_b_mmhg)**2
            u_p_val = math.sqrt(comp_pm + comp_ts + comp_tm + comp_b)

            f.write("**C. Obliczenie niepewności $u(p)$:**\n")
            f.write("Wzór (złożona niepewność standardowa):\n")
            f.write(
                "$$u(p) = \\sqrt{u^2(p_m) + \\left(0.5 \\frac{b}{755}\\right)^2 u^2(t_s) + \\left(0.5 \\frac{b}{755}\\right)^2 u^2(t_m) + \\left(0.5 \\frac{t_s-t_m}{755}\\right)^2 u^2(b)}$$\n")
            f.write("Podstawienie wartości kwadratów składników:\n")
            f.write(f"$$u(p) = \\sqrt{{{
                    comp_pm:.6f} + {comp_ts:.6f} + {comp_tm:.6f} + {comp_b:.6f}}}$$\n")
            f.write(f"$$u(p) = \\sqrt{{{
                    comp_pm + comp_ts + comp_tm + comp_b:.6f}}} = {u_p_val:.4f} \\text{{ mmHg}}$$\n\n")

            # D. Wilgotność w1
            w1 = (p_val / p0) * 100
            results_w1.append(w1)

            f.write("**D. Obliczenie wilgotności względnej $w_1$:**\n")
            f.write(f"$$w_1 = \\frac{{p}}{{p_0}} \\cdot 100\\% = \\frac{{{p_val:.2f}}}{{{
                    p0:.2f}}} \\cdot 100\\% = \\mathbf{{{w1:.2f} \\%}}$$\n\n")

            # E. Niepewność u(w1)
            # u(w) = w * sqrt( (u(p)/p)^2 + (u(p0)/p0)^2 )
            rel_p = (u_p_val / p_val)**2
            rel_p0 = (u_p0 / p0)**2
            u_w1 = w1 * math.sqrt(rel_p + rel_p0)
            results_u_B.append(u_w1)

            f.write("**E. Niepewność pomiaru $u(w_1)$:**\n")
            f.write(
                f"$$u(w_1) = w_1 \\cdot \\sqrt{{\\left(\\frac{{u(p)}}{{p}}\\right)^2 + \\left(\\frac{{u(p_0)}}{{p_0}}\\right)^2}}$$\n")
            f.write(f"$$u(w_1) = {w1:.2f} \\cdot \\sqrt{{\\left(\\frac{{{u_p_val:.4f}}}{{{
                    p_val:.2f}}}\\right)^2 + \\left(\\frac{{{u_p0:.4f}}}{{{p0:.2f}}}\\right)^2}} = {u_w1:.2f} \\%$$\n")
            f.write("---\n")

        # 3. Statystyka końcowa
        avg_w1 = sum(results_w1) / len(results_w1)

        # uA
        sum_sq = sum([(w - avg_w1)**2 for w in results_w1])
        n = len(results_w1)
        ua = math.sqrt(sum_sq / (n * (n - 1)))

        # uB (średnia)
        ub_avg = sum(results_u_B) / n

        # uC
        uc = math.sqrt(ua**2 + ub_avg**2)

        f.write("## 3. Opracowanie statystyczne wyników ($w_1$)\n")
        f.write(f"**Średnia arytmetyczna:**\n")
        f.write(f"$$\\bar{{w}}_1 = \\frac{{\\sum w_i}}{{n}} = \\frac{{{
                sum(results_w1):.2f}}}{{{n}}} = \\mathbf{{{avg_w1:.2f} \\%}}$$\n\n")

        f.write("**Niepewność typu A (statystyczna):**\n")
        f.write(f"$$u_A = \\sqrt{{\\frac{{\\sum (w_i - \\bar{{w}})^2}}{{n(n-1) }}}} = \\sqrt{{\\frac{{{
                sum_sq:.2f}}}{{{n} \\cdot {n-1}}}}} = \\mathbf{{{ua:.2f} \\%}}$$\n\n")

        f.write("**Niepewność typu B (z przyrządów - średnia):**\n")
        f.write(
            f"$$u_B = \\frac{{\\sum u(w_i)}}{{n}} = \\mathbf{{{ub_avg:.2f} \\%}}$$\n\n")

        f.write("**Całkowita niepewność standardowa:**\n")
        f.write(f"$$u(\\bar{{w}}_1) = \\sqrt{{u_A^2 + u_B^2}} = \\sqrt{{{
                ua:.2f}^2 + {ub_avg:.2f}^2}} = \\mathbf{{{uc:.2f} \\%}}$$\n\n")

        # 4. Tabela zbiorcza
        f.write("## 4. Tabela zbiorcza wyników\n")
        f.write(
            "| Nr | $t_m$ | $t_s$ | $p_m$ | $p_0$ | $p$ | $w_1$ | $u(w_1)$ | $w_2$ (Tabl.) |\n")
        f.write("|---|---|---|---|---|---|---|---|---|\n")

        for i, (tm, ts) in enumerate(zip(g_t_m, g_t_s)):
            # Musimy szybko przeliczyć te wartości jeszcze raz do tabeli, albo brać z cache
            # Dla prostoty kodu, obliczam "w locie" tylko do displayu (wartości są te same)
            # W prawdziwym kodzie produkcyjnym lepiej trzymać obiekty, ale tu skrypt jest jednorazowy.
            pm, _, _ = interpolacja(tm)
            p0, _, _ = interpolacja(ts)
            p_val = pm - 0.5 * (ts - tm) * (b_mmhg / 755)
            w1 = (p_val / p0) * 100

            # Pobranie u(w1) z listy
            u_val = results_u_B[i]
            w2_val = tabela_w_2.get((tm, ts))

            f.write(f"| {i+1} | {tm} | {ts} | {pm:.2f} | {p0:.2f} | {
                    p_val:.2f} | **{w1:.2f}** | {u_val:.2f} | {w2_val} |\n")

        # 5. Wyniki końcowe i porównanie
        u_w3 = get_u_instr(5.0)  # Higrometr włosowy
        u_w4 = get_u_instr(2.5)  # Higrometr elektr.
        avg_w2 = sum(tabela_w_2.values()) / len(tabela_w_2)

        f.write("\n## 5. Zestawienie końcowe i porównanie metod\n")
        f.write("### Wyniki końcowe:\n")
        f.write(
            f"- **Psychrometr Assmanna ($w_1$):** $${avg_w1:.2f} \\% \\pm {uc:.2f} \\%$$\n")
        f.write(f"- **Metoda tabelaryczna ($w_2$):** $${avg_w2:.2f} \\%$$\n")
        f.write(
            f"- **Higrometr włosowy ($w_3$):** $${g_w_3} \\% \\pm {u_w3:.2f} \\%$$\n")
        f.write(
            f"- **Higrometr pojemnościowy ($w_4$):** $${g_w_4} \\% \\pm {u_w4:.2f} \\%$$\n\n")

        f.write("### Różnice wskazań (względem metody wzorcowej $w_1$):\n")
        f.write(f"- $w_1 - w_3 = {avg_w1:.2f} - {
                g_w_3} = \\mathbf{{{avg_w1 - g_w_3:.2f} \\text{{ p.proc.}}}}$\n")
        f.write(f"- $w_1 - w_4 = {avg_w1:.2f} - {
                g_w_4} = \\mathbf{{{avg_w1 - g_w_4:.2f} \\text{{ p.proc.}}}}$\n")

    print("Gotowe. Plik 'pelne_obliczenia_obsidian.md' został wygenerowany.")
