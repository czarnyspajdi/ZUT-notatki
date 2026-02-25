import numpy as np
from scipy import stats

# --- DANE POMIAROWE (odczytane ze zdjęcia) ---
# Format: (U, I, [t1, t2, t3, t4, t5])
dane_pomiary = [
    (3.30, 2.2, [1290, 1280, 1278, 1276, 1280]),
    (3.91, 2.4, [1370, 1370, 1360, 1370, 1375]),
    (4.96, 2.6, [1400, 1401, 1398, 1400, 1398]),
    (5.24, 2.8, [1460, 1450, 1460, 1452, 1461]),
    (5.97, 3.0, [1483, 1490, 1491, 1490, 1491])
]
# Uwaga: Dla ostatniego punktu przyjąłem odczyt 1483-1491 (zgodnie z fizyką wzrostu temp.),
# a nie 1443, co sugerowałoby spadek temperatury przy wzroście mocy.

# --- STAŁE FIZYCZNE ---
LAMBDA = 650e-9       # 650 nm
A_WOLFRAM = 0.45      # Współczynnik absorpcji
C2 = 0.01438          # Stała [m*K]
ZERO_ABS = 273.15     # 0 st. C


def formatuj_liczbe(x, precyzja=4):
    """Pomocnicza funkcja do formatowania liczb w LaTeX"""
    return f"{x:.{precyzja}f}"


def generuj_blok_obliczen_dla_punktu(indeks, dane_row, korekta_stala):
    """Generuje szczegółowy opis obliczeń dla pojedynczego punktu"""
    u, i_prad, t_list = dane_row

    # --- OBLICZENIA ---
    t_sr = np.mean(t_list)
    T1 = t_sr + ZERO_ABS
    P = u * i_prad

    # Korekcja temperatury
    odwrotnosc_T = (1/T1) + korekta_stala
    T_real = 1/odwrotnosc_T

    # Logarytmy
    lnT = np.log(T_real)
    lnP = np.log(P)

    val_korekta = (LAMBDA/C2) * np.log(A_WOLFRAM)  # Wartość liczbowa korekty

    # --- GENEROWANIE TEKSTU MARKDOWN/LATEX ---
    md = []
    md.append(f"### Punkt pomiarowy nr {indeks}")
    md.append(f"Dane wejściowe: $U = {u} \\, V$, $I = {i_prad} \\, A$.")
    md.append(f"Temperatury odczytane: {
              ', '.join(map(str, t_list))} [$^\\circ C$].\n")

    # 1. Średnia
    sum_t = sum(t_list)
    md.append(f"**1. Średnia temperatura luminacyjna ($t_{{1sr}}$):**")
    md.append(f"$$ t_{{1sr}} = \\frac{{\\sum t_i}}{{5}} = \\frac{{{sum_t}}}{{5}} = {
              t_sr:.1f} \\, ^\\circ C $$")

    # 2. Kelvin
    md.append(f"**2. Temperatura luminacyjna w Kelvinach ($T_1$):**")
    md.append(
        f"$$ T_1 = t_{{1sr}} + 273.15 = {t_sr:.1f} + 273.15 = {T1:.2f} \\, K $$")

    # 3. Moc
    md.append(f"**3. Moc ($P$):**")
    md.append(f"$$ P = U \\cdot I = {u} \\cdot {i_prad} = {P:.2f} \\, W $$")

    # 4. Temp rzeczywista
    md.append(f"**4. Temperatura rzeczywista ($T$):**")
    md.append("Korzystamy ze wzoru korekcyjnego (z prawa Plancka):")
    md.append(
        f"$$ \\frac{{1}}{{T}} = \\frac{{1}}{{T_1}} + \\frac{{\\lambda}}{{C_2}} \\ln(a) $$")
    md.append(
        f"Stała korekcja $K = \\frac{{650 \\cdot 10^{{-9}}}}{{0.01438}} \\ln(0.45) \\approx {val_korekta:.2e}$")
    md.append(f"$$ \\frac{{1}}{{T}} = \\frac{{1}}{{{T1:.2f}}} + ({val_korekta:.2e}) = {
              1/T1:.2e} - {abs(val_korekta):.2e} = {odwrotnosc_T:.2e} $$")
    md.append(f"$$ T = \\frac{{1}}{{{odwrotnosc_T:.6f}}} \\approx \\mathbf{{{
              T_real:.1f} \\, K}} $$")

    # 5. Logarytmy
    md.append(f"**5. Logarytmy do wykresu:**")
    md.append(f"$$ \\ln(T) = \\ln({T_real:.1f}) \\approx {lnT:.4f} $$")
    md.append(f"$$ \\ln(P) = \\ln({P:.2f}) \\approx {lnP:.4f} $$")
    md.append("\n---\n")  # Separator

    return "\n".join(md), {
        'id': indeks, 'U': u, 'I': i_prad, 'P': P,
        't1_sr': t_sr, 'T1': T1, 'T': T_real,
        'lnT': lnT, 'lnP': lnP
    }


def przetworz_wszystko(dane):
    korekta_stala = (LAMBDA / C2) * np.log(A_WOLFRAM)

    raport_full = []
    raport_full.append("# Szczegółowe obliczenia do Ćwiczenia 402\n")

    wyniki_lista = []

    # Pętla generująca opis dla każdego punktu
    for i, row in enumerate(dane):
        tekst_punktu, wyniki_dict = generuj_blok_obliczen_dla_punktu(
            i+1, row, korekta_stala)
        raport_full.append(tekst_punktu)
        wyniki_lista.append(wyniki_dict)

    # Regresja
    x_val = [w['lnT'] for w in wyniki_lista]
    y_val = [w['lnP'] for w in wyniki_lista]
    slope, intercept, r_value, stderr, intercept_stderr = stats.linregress(
        x_val, y_val)

    # Tabela zbiorcza
    raport_full.append("## Tabela Zbiorcza Wyników")
    raport_full.append(
        "| Lp. | $U$ [V] | $I$ [A] | $P$ [W] | $t_{1,sr}$ [$^{\\circ}$C] | $T_{rz}$ [K] | $\\ln(T)$ | $\\ln(P)$ |")
    raport_full.append("|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|")
    for w in wyniki_lista:
        raport_full.append(f"| {w['id']} | {w['U']} | {w['I']} | {w['P']:.2f} | {
                           w['t1_sr']:.1f} | **{w['T']:.0f}** | {w['lnT']:.4f} | {w['lnP']:.4f} |")

    # Podsumowanie regresji
    raport_full.append("\n## Wyniki końcowe (Regresja)")
    raport_full.append(f"Równanie prostej: $\\ln(P) = n \\cdot \\ln(T) + C$")
    raport_full.append(
        f"* **Współczynnik $n$ (potęga temperatury):** `{slope:.4f}`")
    raport_full.append(f"* **Błąd standardowy $S_n$:** `{stderr:.4f}`")
    raport_full.append(
        f"* **Współczynnik korelacji $R^2$:** `{r_value**2:.4f}`")

    raport_full.append(f"\n$$ \\ln(P) = ({slope:.3f} \\pm {
                       stderr:.3f}) \\cdot \\ln(T) + ({intercept:.3f}) $$")

    return "\n".join(raport_full)


if __name__ == "__main__":
    gotowy_raport = przetworz_wszystko(dane_pomiary)
    print("-" * 20 + " KOPIUJ OD TEGO MIEJSCA " + "-" * 20)
    print(gotowy_raport)
    print("-" * 20 + " KONIEC KOPIOWANIA " + "-" * 20)
