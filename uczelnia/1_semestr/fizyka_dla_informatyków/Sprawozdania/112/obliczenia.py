import math

def formatuj_raport(nazwa, l_pomiary, S_koncowe, a_tab_tex, a_tab_val, S_poczatkowe=0.0, T_wrzenia=99.74, T0=21.0):
    """
    Funkcja wykonuje obliczenia i zwraca sformatowany raport w Markdown/LaTeX.
    Wersja ROZSZERZONA - wypisuje wszystkie dane pośrednie.
    """
    output = [] 
    
    # --- 1. STAŁE I DOKŁADNOŚCI PRZYRZĄDÓW ---
    dokladnosc_termometru = 1.0       
    dokladnosc_tabeli = 0.01          
    dokladnosc_suwmiarki = 0.00001    
    dokladnosc_czujnika = 0.00001     

    # --- 2. OBLICZENIA WARTOŚCI ŚREDNICH ---
    l0 = sum(l_pomiary) / len(l_pomiary)
    deltaT = T_wrzenia - T0
    deltaL = S_koncowe - S_poczatkowe

    # Zabezpieczenie przed dzieleniem przez zero
    if l0 == 0 or deltaT == 0: return "Błąd: Dzielenie przez zero."

    # --- 3. GŁÓWNY WZÓR NA ALPHA ---
    a = deltaL / (l0 * deltaT)

    # --- 4. RACHUNEK NIEPEWNOŚCI (OBLICZENIA) ---
    
    # Typ B (z przyrządów) - obliczamy wartości
    uB_T0 = dokladnosc_termometru / math.sqrt(3)
    uB_T_wrz = dokladnosc_tabeli / math.sqrt(3)
    u_deltaT = math.sqrt(uB_T_wrz**2 + uB_T0**2)
    
    uB_l0 = dokladnosc_suwmiarki / math.sqrt(3)
    uB_deltaL = dokladnosc_czujnika / math.sqrt(3)

    # Typ A (statystyczna dla długości)
    n = len(l_pomiary)
    suma_kwadratow = sum([(l - l0)**2 for l in l_pomiary])
    if n > 1:
        ua_l0 = math.sqrt(suma_kwadratow / (n * (n - 1)))
    else:
        ua_l0 = 0.0
    
    # Niepewność złożona (składniki)
    try: 
        # Kwadrat niepewności względnej wydłużenia
        wzgl_dL_sq = (uB_deltaL / deltaL)**2
    except ZeroDivisionError: 
        wzgl_dL_sq = 0
    
    # Kwadrat niepewności względnej długości (A + B)
    wzgl_l0_sq = (1 / l0**2) * (ua_l0**2 + uB_l0**2)
    
    # Kwadrat niepewności względnej temperatury
    wzgl_dT_sq = (u_deltaT / deltaT)**2
    
    # Suma i pierwiastek
    suma_wzgl = wzgl_dL_sq + wzgl_l0_sq + wzgl_dT_sq
    ua_a = a * math.sqrt(suma_wzgl)

    # --- 5. BŁĄD WZGLĘDNY ---
    blad_wzgledny = abs(a - a_tab_val) / a_tab_val * 100


    # ==========================================
    # --- 6. GENEROWANIE RAPORTU (WYPISYWANIE) ---
    # ==========================================

    output.append(f"## Materiał: {nazwa}")
    
    # Sekcja 1: Dane wejściowe
    output.append("### 1. Dane pomiarowe i stałe")
    output.append(f"* **Pomiary długości $l_0$:** {l_pomiary} m")
    output.append(f"* **Odczyt czujnika $S$:** {S_koncowe} m")
    output.append(f"* **Temp. wrzenia $T_{{wrz}}$:** {T_wrzenia} $^\\circ$C")
    output.append(f"* **Temp. otoczenia $T_0$:** {T0} $^\\circ$C")
    output.append(f"* **Dokładności przyrządów:**")
    output.append(f"    * Termometr: $\\Delta T_0 = {dokladnosc_termometru}$ K")
    output.append(f"    * Tabela wrzenia: $\\Delta T_{{tab}} = {dokladnosc_tabeli}$ K")
    output.append(f"    * Suwmiarka: $\\Delta l = {dokladnosc_suwmiarki}$ m")
    output.append(f"    * Czujnik: $\\Delta S = {dokladnosc_czujnika}$ m")
    output.append("") 

    # Sekcja 2: Wyniki pośrednie
    output.append(f"### 2. Obliczenia wielkości fizycznych")
    output.append(f"**a) Średnia długość początkowa:**")
    output.append(f"$$\\overline{{l}}_0 = \\frac{{{sum(l_pomiary):.5f}}}{{{n}}} = {l0:.5f} \\, m$$")
    
    output.append(f"**b) Różnica temperatur:**")
    output.append(f"$$\\Delta T = T_{{wrz}} - T_0 = {T_wrzenia} - {T0} = {deltaT:.2f} \\, K$$")
    
    output.append(f"**c) Wydłużenie bezwzględne:**")
    output.append(f"$$\\Delta l = S_{{końc}} - S_{{pocz}} = {S_koncowe} - {S_poczatkowe} = {deltaL:.5f} \\, m$$")
    
    output.append(f"**d) Współczynnik rozszerzalności:**")
    output.append(f"$$\\alpha = \\frac{{{deltaL:.5f}}}{{{l0:.5f} \\cdot {deltaT:.2f}}} = \\mathbf{{{a*1e6:.2f} \\cdot 10^{{-6}} \\, K^{{-1}}}}$$")

    # Sekcja 3: Szczegółowa niepewność (TO JEST NOWE)
    output.append(f"### 3. Szczegółowa analiza niepewności")
    
    output.append(f"**a) Niepewności standardowe typu B:**")
    output.append(f"* Termometr: $u_B(T_0) = \\frac{{{dokladnosc_termometru}}}{{\\sqrt{{3}}}} = {uB_T0:.4f}$ K")
    output.append(f"* Tabela wrzenia: $u_B(T_{{wrz}}) = \\frac{{{dokladnosc_tabeli}}}{{\\sqrt{{3}}}} = {uB_T_wrz:.4f}$ K")
    output.append(f"* Suwmiarka: $u_B(l_0) = \\frac{{{dokladnosc_suwmiarki}}}{{\\sqrt{{3}}}} = {uB_l0:.7f}$ m")
    output.append(f"* Czujnik wydłużenia: $u_B(\\Delta l) = \\frac{{{dokladnosc_czujnika}}}{{\\sqrt{{3}}}} = {uB_deltaL:.7f}$ m")
    
    output.append(f"**b) Niepewność różnicy temperatur:**")
    output.append(f"$$u(\\Delta T) = \\sqrt{{u_B^2(T_{{wrz}}) + u_B^2(T_0)}} = \\sqrt{{{uB_T_wrz:.4f}^2 + {uB_T0:.4f}^2}} = {u_deltaT:.4f} \\, K$$")
    
    output.append(f"**c) Niepewność typu A:**")
    output.append(f"$$u_A(l_0) = \\sqrt{{\\frac{{\\sum (l_i - \\overline{{l}})^2}}{{n(n-1)}}}} = {ua_l0:.7f} \\, m$$")
    
    output.append(f"**d) Udziały niepewności:**")
    output.append(f"* Od wydłużenia: $(\\frac{{u(\\Delta l)}}{{\\Delta l}})^2 = {wzgl_dL_sq:.2e}$")
    output.append(f"* Od długości: $\\frac{{1}}{{l_0^2}}(u_A^2 + u_B^2) = {wzgl_l0_sq:.2e}$")
    output.append(f"* Od temperatury: $(\\frac{{u(\\Delta T)}}{{\\Delta T}})^2 = {wzgl_dT_sq:.2e}$")
    output.append(f"* **Suma pod pierwiastkiem:** ${suma_wzgl:.2e}$")
    
    output.append(f"**e) Niepewność całkowita:**")
    output.append(f"$$u(\\alpha) = \\alpha \\cdot \\sqrt{{{suma_wzgl:.4f}}} = {ua_a*1e6:.2f} \\cdot 10^{{-6}} \\, K^{{-1}}$$")

    # Sekcja 4: Podsumowanie
    output.append(f"\n> **Zestawienie końcowe:**")
    output.append(f"> * **Wynik z pomiaru:** $\\alpha = ({a*1e6:.2f} \\pm {ua_a*1e6:.2f}) \\cdot 10^{{-6}} \\, K^{{-1}}$")
    output.append(f"> * **Wartość tablicowa:** $\\alpha_{{tab}} \\approx {a_tab_tex} \\, K^{{-1}}$")
    
    output.append(f"> * **Błąd względny:**")
    output.append(f">   $$\\delta = \\frac{{|{a*1e6:.2f} - {a_tab_val*1e6:.1f}|}}{{{a_tab_val*1e6:.1f}}} \\cdot 100\\% = \\mathbf{{{blad_wzgledny:.1f}\\%}}$$")
    
    output.append("\n---\n")
    return "\n".join(output)

# --- KONFIGURACJA I URUCHOMIENIE ---

# Dane wspólne
T_w = 99.71  # Temp. wrzenia [C]
T_p = 21.0   # Temp. pokojowa [C]

# --- WYWOŁANIA DLA MATERIAŁÓW ---
tresc = ""

# 1. Mosiądz
tresc += formatuj_raport(
    nazwa="Mosiądz", 
    l_pomiary=[0.40480, 0.40470, 0.40460], 
    S_koncowe=0.00021, 
    a_tab_tex="19 \\cdot 10^{-6}", 
    a_tab_val=19e-6, 
    T_wrzenia=T_w, T0=T_p
)

# 2. Glin
tresc += formatuj_raport(
    nazwa="Glin", 
    l_pomiary=[0.40370, 0.40360, 0.40360], 
    S_koncowe=0.00010, 
    a_tab_tex="25 \\cdot 10^{-6}", 
    a_tab_val=25e-6, 
    T_wrzenia=T_w, T0=T_p
)

# 3. Stal
tresc += formatuj_raport(
    nazwa="Stal", 
    l_pomiary=[0.40520, 0.40520, 0.40520], 
    S_koncowe=0.00031, 
    a_tab_tex="12 \\cdot 10^{-6}", 
    a_tab_val=12e-6, 
    T_wrzenia=T_w, T0=T_p
)

# --- ZAPIS DO PLIKU ---
nazwa_pliku = "wyniki_szczegolowe.md"
with open(nazwa_pliku, "w", encoding="utf-8") as f:
    f.write(tresc)

print("="*40)
print(f"SUKCES! Wygenerowano plik: {nazwa_pliku}")
print("Raport zawiera teraz WSZYSTKIE dane pośrednie (uA, uB, składniki błędu).")
print("Otwórz plik w Obsidianie.")
print("="*40)
