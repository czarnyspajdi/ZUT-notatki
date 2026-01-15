import math

# Stałe i zmienne
# Stałe, pomiary
g_b = 1015  # ciśnienie atmosferyczne
g_t_s = [22.5, 21.8, 21.4, 21.8, 21.6]  # temperatura – suchy
g_t_m = [17, 18.2, 17.8, 17.8, 18.2]  # temperatura – mokry
g_w_3 = 35  # higrometr włoskowy
g_w_4 = 30.5  # higrometr pojemnościowy – uszkodzony ekran xd
dokladnosc_termometru = 0.1
dokladnosc_barometru = 1 * 0.75
dokladnosc_tabeli = (9.84 - 9.21) / 2

# Prężność pary – mokry

# Prężność pary – mokry

# Zmienne
w_1 = 0  # za pomocą psychrometru aspieracyjnego Assmana | do policzenia
w_2 = 0  # ze wskazań termometru suchego i mokrego oraz tablic psychrometryczny
p_0 = 0  # prężność pary nasyconej – suchy
p_m = 0  # prężność pary nasyconej – mokry
p = 0  # prężność pary nienasyconej – suchy | potrzebna w punkcie h)

# tabelka p w liście
tabela_p = {
    16: 13.63,
    17: 14.53,
    18: 15.48,
    19: 16.48,
    20: 17.54,
    21: 18.65,
    22: 19.83,
    23: 21.07,
}

tabela_w_2 = {
    (17, 22.5): 58,
    (18.2, 21.8): 69,
    (17.8, 21.4): 71,
    (17.8, 21.8): 68,
    (18.2, 21.6): 72
}

# Funkcje


def p_m_lub_t_i_niepewnosc(t_m):  # to już działa
    jest_calkowita = float(t_m).is_integer()
    if jest_calkowita:
        t = int(t_m)

        if (t-1) not in tabela_p or (t+1) not in tabela_p:
            return None, None  # Brak danych w tabeli

        p_srodek = tabela_p[t]
        p_lewo = tabela_p[t-1]
        p_prawo = tabela_p[t+1]

        p_wynik = p_srodek

        roznica_lewa = p_srodek - p_lewo
        roznica_prawa = p_prawo - p_srodek

        max_roznica = max(roznica_lewa, roznica_prawa)
        niepewnosc = max_roznica / 2
    else:
        t_1 = int(t_m)
        t_2 = t_1 + 1

        if t_1 not in tabela_p or t_2 not in tabela_p:
            return None, None

        p_m_1 = tabela_p[t_1]
        p_m_2 = tabela_p[t_2]

        delta_t = t_m - t_1
        p_wynik = p_m_1 + (p_m_2 - p_m_1) * delta_t

        niepewnosc = (p_m_2 - p_m_1) / 2

    return p_wynik, niepewnosc


def p_nienasycona(p_m, t_s, t_m, b):
    return p_m - ((t_s - t_m) / 2) * (b/755)

# niepewności standardowe


def niepewnosc_termometru_suchego(delta_t_s=dokladnosc_termometru):
    return delta_t_s / math.sqrt(3)


def niepewnosc_termometru_mokrego(delta_t_m=dokladnosc_termometru):
    return delta_t_m / math.sqrt(3)


def niepewnosc_barometru(delta_b=dokladnosc_barometru):
    return delta_b / math.sqrt(3)


def niepewnosc_tabeli(p_0=dokladnosc_tabeli):
    return p_0/math.sqrt(3)


def niepewnosc_higrometru_elektronicznego(dokladnosc_producenta=2.5):
    return dokladnosc_producenta / math.sqrt(3)


def niepewnosc_higrometru_wlosowego(dokladnosc_odczytu=5.0):
    return dokladnosc_odczytu / math.sqrt(3)


def niepewnosc_pary_nienasyconej(p_m, u_p_m, t_s, t_m, u_t_s, u_t_m, b_hpa, u_b_hpa):
    b_mmhg = b_hpa * 0.75
    u_b_mmhg = u_b_hpa * 0.75

    c1 = u_p_m**2

    A = 0.5 * (b_mmhg / 755)
    c2 = (A**2) * (u_t_s**2)
    c3 = (A**2) * (u_t_m**2)

    B = 0.5 * (t_s - t_m) / 755
    c4 = (B**2) * (u_b_mmhg**2)

    return math.sqrt(c1 + c2 + c3 + c4)


def wilgotnosc_wzgledna(p, p_0):
    return (p/p_0)*100


def niepewnosc_wilgotnosci_wzglednej_B(w1, p, u_p, p_0, u_p_0):
    c1 = (u_p / p) ** 2
    c2 = (u_p_0 / p_0) ** 2
    return w1 * math.sqrt(c1 + c2)


def wartosc_srednia_w_1(w_1):
    return sum(w_1) / len(w_1)


def niepewnosc_a(w_1, w_1_srednie):
    n = len(w_1)
    if n <= 1:
        return 0
    suma_kwadratow = sum((w - w_1_srednie) ** 2 for w in w_1)
    return math.sqrt(suma_kwadratow / (n * (n - 1)))


def w_2(t_s, t_m):
    return t_s - t_m


if __name__ == "__main__":
    b = g_b * 0.75

    # Niepewności przyrządów
    u_ts = niepewnosc_termometru_suchego()
    u_tm = niepewnosc_termometru_mokrego()
    u_b = niepewnosc_barometru()  # w hPa

    # Niepewności pozostałych metod
    u_w3 = niepewnosc_higrometru_wlosowego()
    u_w4 = niepewnosc_higrometru_elektronicznego()

    w = []
    w2 = []
    ub_lista = []

    for t_m, t_s in zip(g_t_m, g_t_s):
        print(f"=== Pomiar (tm={t_m}, ts={t_s}) ===")

        # Interpolacja i przeliczenie na niepewność standardową
        p_m, delta_p_m = p_m_lub_t_i_niepewnosc(t_m)
        u_p_m = delta_p_m / math.sqrt(3)  # POPRAWKA: Dzielenie przez sqrt(3)

        p_0, delta_p_0 = p_m_lub_t_i_niepewnosc(t_s)
        u_p_0 = delta_p_0 / math.sqrt(3)  # POPRAWKA: Dzielenie przez sqrt(3)

        # Obliczenia dla metody w1
        p_nie = p_nienasycona(p_m, t_s, t_m, b)

        niepewnosc_koncowa = niepewnosc_pary_nienasyconej(
            p_m, u_p_m, t_s, t_m, u_ts, u_tm, g_b, u_b
        )

        w_1_val = wilgotnosc_wzgledna(p_nie, p_0)
        w.append(w_1_val)

        ub_val = niepewnosc_wilgotnosci_wzglednej_B(
            w_1_val, p_nie, niepewnosc_koncowa, p_0, u_p_0)
        ub_lista.append(ub_val)

        w_2_val = tabela_w_2.get((t_m, t_s))
        w2.append(w_2_val)
        print(f"w1: {w_1_val:.2f}% | u(w1): {ub_val:.2f} | w2: {
              w_2_val}%")  # Zmodyfikowany print

        print(f"w1: {w_1_val:.2f}% | u(w1): {ub_val:.2f}")

    # Wyniki końcowe
    srednie_w1 = wartosc_srednia_w_1(w)
    srednie_w2 = sum(w2) / len(w2)
    ua = niepewnosc_a(w, srednie_w1)
    ub_koncowe = sum(ub_lista) / len(ub_lista)
    uc = math.sqrt(ua**2 + ub_koncowe**2)

    print("\n=== WYNIKI KOŃCOWE ===")
    print(f"Psychrometr (w1): {srednie_w1:.2f}% +/- {uc:.2f}%")
    print(f"Termometr suchy i mokry (w2): {srednie_w2:.2f}% +/- {uc:.2f}%")
    print(f"Higrometr włosowy (w3): {g_w_3}% +/- {u_w3:.2f}%")
    print(f"Higrometr elektr. (w4): {g_w_4}% +/- {u_w4:.2f}%")

    # Różnice do wniosków
    print(f"\nRóżnica w1 - w3: {srednie_w1 - g_w_3:.2f} p.proc")
    print(f"Różnica w1 - w4: {srednie_w1 - g_w_4:.2f} p.proc")
