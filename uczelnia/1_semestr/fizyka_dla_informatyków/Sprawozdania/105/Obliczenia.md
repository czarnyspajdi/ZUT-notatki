# Obliczenia
## 1. Dane wstępne i niepewności przyrządów
- Ciśnienie atmosferyczne: $b = 1015 \text{ hPa} = 761.25 \text{ mmHg}$
- Niepewność standardowa termometrów: $$u(t) = \frac{0.1}{\sqrt{3}} = 0.0577 \, ^\circ\text{C}$$
- Niepewność standardowa barometru (w mmHg): $$u(b) = \frac{0.75}{\sqrt{3}} = 0.4330 \text{ mmHg}$$

## 2. Obliczenia krok po kroku dla każdego pomiaru
### Pomiar nr 1
Dane: $t_m = 17^\circ\text{C}$, $t_s = 22.5^\circ\text{C}$

**A. Wyznaczenie prężności pary nasyconej:**
- Dla termometru mokrego ($t_m=17$): Wartość z tabeli dla $t=17$.
  $$p_m = 14.53 \text{ mmHg}$$
  Niepewność odczytu: $\Delta p_m = 0.475$.
  $$u(p_m) = \frac{0.475}{\sqrt{3}} = 0.2742 \text{ mmHg}$$
- Dla termometru suchego ($t_s=22.5$): Interpolacja między 22°C (19.83) a 23°C (21.07).
  $$p_0 = 20.45 \text{ mmHg}$$
  $$u(p_0) = \frac{0.620}{\sqrt{3}} = 0.3580 \text{ mmHg}$$

**B. Obliczenie prężności pary nienasyconej $p$:**
Wzór: $$p = p_m - 0.5 \cdot (t_s - t_m) \cdot \frac{b}{755}$$
Podstawienie:
$$p = 14.53 - 0.5 \cdot (22.5 - 17) \cdot \frac{761.2}{755}$$
$$p = 14.53 - 2.7728 = \mathbf{11.76 \text{ mmHg}}$$

**C. Obliczenie niepewności $u(p)$:**
$$u(p) = \sqrt{u^2(p_m) + \left(0.5 \frac{b}{755}\right)^2 u^2(t_s) + \left(0.5 \frac{b}{755}\right)^2 u^2(t_m) + \left(0.5 \frac{t_s-t_m}{755}\right)^2 u^2(b)}$$
$$u(p) = \sqrt{0.075208 + 0.000847 + 0.000847 + 0.000002}$$
$$u(p) = \sqrt{0.076905} = 0.2773 \text{ mmHg}$$

**D. Obliczenie wilgotności względnej $w_1$:**
$$w_1 = \frac{p}{p_0} \cdot 100\% = \frac{11.76}{20.45} \cdot 100\% = \mathbf{57.49 \%}$$

**E. Niepewność pomiaru $u(w_1)$:**
$$u(w_1) = w_1 \cdot \sqrt{\left(\frac{u(p)}{p}\right)^2 + \left(\frac{u(p_0)}{p_0}\right)^2}$$
$$u(w_1) = 57.49 \cdot \sqrt{\left(\frac{0.2773}{11.76}\right)^2 + \left(\frac{0.3580}{20.45}\right)^2} = 1.69 \%$$
---
### Pomiar nr 2
Dane: $t_m = 18.2^\circ\text{C}$, $t_s = 21.8^\circ\text{C}$

**A. Wyznaczenie prężności pary nasyconej:**
- Dla termometru mokrego ($t_m=18.2$): Interpolacja między 18°C (15.48) a 19°C (16.48).
  $$p_m = 15.68 \text{ mmHg}$$
  Niepewność odczytu: $\Delta p_m = 0.500$.
  $$u(p_m) = \frac{0.500}{\sqrt{3}} = 0.2887 \text{ mmHg}$$
- Dla termometru suchego ($t_s=21.8$): Interpolacja między 21°C (18.65) a 22°C (19.83).
  $$p_0 = 19.59 \text{ mmHg}$$
  $$u(p_0) = \frac{0.590}{\sqrt{3}} = 0.3406 \text{ mmHg}$$

**B. Obliczenie prężności pary nienasyconej $p$:**
Wzór: $$p = p_m - 0.5 \cdot (t_s - t_m) \cdot \frac{b}{755}$$
Podstawienie:
$$p = 15.68 - 0.5 \cdot (21.8 - 18.2) \cdot \frac{761.2}{755}$$
$$p = 15.68 - 1.8149 = \mathbf{13.87 \text{ mmHg}}$$

**C. Obliczenie niepewności $u(p)$:**
Wzór (złożona niepewność standardowa):
$$u(p) = \sqrt{u^2(p_m) + \left(0.5 \frac{b}{755}\right)^2 u^2(t_s) + \left(0.5 \frac{b}{755}\right)^2 u^2(t_m) + \left(0.5 \frac{t_s-t_m}{755}\right)^2 u^2(b)}$$
Podstawienie wartości kwadratów składników:
$$u(p) = \sqrt{0.083333 + 0.000847 + 0.000847 + 0.000001}$$
$$u(p) = \sqrt{0.085029} = 0.2916 \text{ mmHg}$$

**D. Obliczenie wilgotności względnej $w_1$:**
$$w_1 = \frac{p}{p_0} \cdot 100\% = \frac{13.87}{19.59} \cdot 100\% = \mathbf{70.76 \%}$$

**E. Niepewność pomiaru $u(w_1)$:**
$$u(w_1) = w_1 \cdot \sqrt{\left(\frac{u(p)}{p}\right)^2 + \left(\frac{u(p_0)}{p_0}\right)^2}$$
$$u(w_1) = 70.76 \cdot \sqrt{\left(\frac{0.2916}{13.87}\right)^2 + \left(\frac{0.3406}{19.59}\right)^2} = 1.93 \%$$
---
### Pomiar nr 3
Dane: $t_m = 17.8^\circ\text{C}$, $t_s = 21.4^\circ\text{C}$

**A. Wyznaczenie prężności pary nasyconej:**
- Dla termometru mokrego ($t_m=17.8$): Interpolacja między 17°C (14.53) a 18°C (15.48).
  $$p_m = 15.29 \text{ mmHg}$$
  Niepewność odczytu: $\Delta p_m = 0.475$.
  $$u(p_m) = \frac{0.475}{\sqrt{3}} = 0.2742 \text{ mmHg}$$
- Dla termometru suchego ($t_s=21.4$): Interpolacja między 21°C (18.65) a 22°C (19.83).
  $$p_0 = 19.12 \text{ mmHg}$$
  $$u(p_0) = \frac{0.590}{\sqrt{3}} = 0.3406 \text{ mmHg}$$

**B. Obliczenie prężności pary nienasyconej $p$:**
Wzór: $$p = p_m - 0.5 \cdot (t_s - t_m) \cdot \frac{b}{755}$$
Podstawienie:
$$p = 15.29 - 0.5 \cdot (21.4 - 17.8) \cdot \frac{761.2}{755}$$
$$p = 15.29 - 1.8149 = \mathbf{13.48 \text{ mmHg}}$$

**C. Obliczenie niepewności $u(p)$:**
Wzór (złożona niepewność standardowa):
$$u(p) = \sqrt{u^2(p_m) + \left(0.5 \frac{b}{755}\right)^2 u^2(t_s) + \left(0.5 \frac{b}{755}\right)^2 u^2(t_m) + \left(0.5 \frac{t_s-t_m}{755}\right)^2 u^2(b)}$$
Podstawienie wartości kwadratów składników:
$$u(p) = \sqrt{0.075208 + 0.000847 + 0.000847 + 0.000001}$$
$$u(p) = \sqrt{0.076904} = 0.2773 \text{ mmHg}$$

**D. Obliczenie wilgotności względnej $w_1$:**
$$w_1 = \frac{p}{p_0} \cdot 100\% = \frac{13.48}{19.12} \cdot 100\% = \mathbf{70.47 \%}$$

**E. Niepewność pomiaru $u(w_1)$:**
$$u(w_1) = w_1 \cdot \sqrt{\left(\frac{u(p)}{p}\right)^2 + \left(\frac{u(p_0)}{p_0}\right)^2}$$
$$u(w_1) = 70.47 \cdot \sqrt{\left(\frac{0.2773}{13.48}\right)^2 + \left(\frac{0.3406}{19.12}\right)^2} = 1.92 \%$$
---
### Pomiar nr 4
Dane: $t_m = 17.8^\circ\text{C}$, $t_s = 21.8^\circ\text{C}$

**A. Wyznaczenie prężności pary nasyconej:**
- Dla termometru mokrego ($t_m=17.8$): Interpolacja między 17°C (14.53) a 18°C (15.48).
  $$p_m = 15.29 \text{ mmHg}$$
  Niepewność odczytu: $\Delta p_m = 0.475$.
  $$u(p_m) = \frac{0.475}{\sqrt{3}} = 0.2742 \text{ mmHg}$$
- Dla termometru suchego ($t_s=21.8$): Interpolacja między 21°C (18.65) a 22°C (19.83).
  $$p_0 = 19.59 \text{ mmHg}$$
  $$u(p_0) = \frac{0.590}{\sqrt{3}} = 0.3406 \text{ mmHg}$$

**B. Obliczenie prężności pary nienasyconej $p$:**
Wzór: $$p = p_m - 0.5 \cdot (t_s - t_m) \cdot \frac{b}{755}$$
Podstawienie:
$$p = 15.29 - 0.5 \cdot (21.8 - 17.8) \cdot \frac{761.2}{755}$$
$$p = 15.29 - 2.0166 = \mathbf{13.27 \text{ mmHg}}$$

**C. Obliczenie niepewności $u(p)$:**
Wzór (złożona niepewność standardowa):
$$u(p) = \sqrt{u^2(p_m) + \left(0.5 \frac{b}{755}\right)^2 u^2(t_s) + \left(0.5 \frac{b}{755}\right)^2 u^2(t_m) + \left(0.5 \frac{t_s-t_m}{755}\right)^2 u^2(b)}$$
Podstawienie wartości kwadratów składników:
$$u(p) = \sqrt{0.075208 + 0.000847 + 0.000847 + 0.000001}$$
$$u(p) = \sqrt{0.076904} = 0.2773 \text{ mmHg}$$

**D. Obliczenie wilgotności względnej $w_1$:**
$$w_1 = \frac{p}{p_0} \cdot 100\% = \frac{13.27}{19.59} \cdot 100\% = \mathbf{67.74 \%}$$

**E. Niepewność pomiaru $u(w_1)$:**
$$u(w_1) = w_1 \cdot \sqrt{\left(\frac{u(p)}{p}\right)^2 + \left(\frac{u(p_0)}{p_0}\right)^2}$$
$$u(w_1) = 67.74 \cdot \sqrt{\left(\frac{0.2773}{13.27}\right)^2 + \left(\frac{0.3406}{19.59}\right)^2} = 1.84 \%$$
---
### Pomiar nr 5
Dane: $t_m = 18.2^\circ\text{C}$, $t_s = 21.6^\circ\text{C}$

**A. Wyznaczenie prężności pary nasyconej:**
- Dla termometru mokrego ($t_m=18.2$): Interpolacja między 18°C (15.48) a 19°C (16.48).
  $$p_m = 15.68 \text{ mmHg}$$
  Niepewność odczytu: $\Delta p_m = 0.500$.
  $$u(p_m) = \frac{0.500}{\sqrt{3}} = 0.2887 \text{ mmHg}$$
- Dla termometru suchego ($t_s=21.6$): Interpolacja między 21°C (18.65) a 22°C (19.83).
  $$p_0 = 19.36 \text{ mmHg}$$
  $$u(p_0) = \frac{0.590}{\sqrt{3}} = 0.3406 \text{ mmHg}$$

**B. Obliczenie prężności pary nienasyconej $p$:**
Wzór: $$p = p_m - 0.5 \cdot (t_s - t_m) \cdot \frac{b}{755}$$
Podstawienie:
$$p = 15.68 - 0.5 \cdot (21.6 - 18.2) \cdot \frac{761.2}{755}$$
$$p = 15.68 - 1.7141 = \mathbf{13.97 \text{ mmHg}}$$

**C. Obliczenie niepewności $u(p)$:**
Wzór (złożona niepewność standardowa):
$$u(p) = \sqrt{u^2(p_m) + \left(0.5 \frac{b}{755}\right)^2 u^2(t_s) + \left(0.5 \frac{b}{755}\right)^2 u^2(t_m) + \left(0.5 \frac{t_s-t_m}{755}\right)^2 u^2(b)}$$
Podstawienie wartości kwadratów składników:
$$u(p) = \sqrt{0.083333 + 0.000847 + 0.000847 + 0.000001}$$
$$u(p) = \sqrt{0.085029} = 0.2916 \text{ mmHg}$$

**D. Obliczenie wilgotności względnej $w_1$:**
$$w_1 = \frac{p}{p_0} \cdot 100\% = \frac{13.97}{19.36} \cdot 100\% = \mathbf{72.15 \%}$$

**E. Niepewność pomiaru $u(w_1)$:**
$$u(w_1) = w_1 \cdot \sqrt{\left(\frac{u(p)}{p}\right)^2 + \left(\frac{u(p_0)}{p_0}\right)^2}$$
$$u(w_1) = 72.15 \cdot \sqrt{\left(\frac{0.2916}{13.97}\right)^2 + \left(\frac{0.3406}{19.36}\right)^2} = 1.97 \%$$
---
## 3. Opracowanie statystyczne wyników ($w_1$)
**Średnia arytmetyczna:**
$$\bar{w}_1 = \frac{\sum w_i}{n} = \frac{338.61}{5} = \mathbf{67.72 \%}$$

**Niepewność typu A (statystyczna):**
$$u_A = \sqrt{\frac{\sum (w_i - \bar{w})^2}{n(n-1) }} = \sqrt{\frac{141.00}{5 \cdot 4}} = \mathbf{2.66 \%}$$

**Niepewność typu B (z przyrządów - średnia):**
$$
u_B = \frac{1}{n} \sum_{i=1}^{n} u(w_i)
    = \frac{1.69 + 1.93 + 1.92 + 1.84 + 1.97}{5}
    = 1.87\%
$$

**Całkowita niepewność standardowa:**
$$u(\bar{w}_1) = \sqrt{u_A^2 + u_B^2} = \sqrt{2.66^2 + 1.87^2} = \mathbf{3.25 \%}$$
## 4. Zestawienie końcowe i porównanie metod
### Wyniki końcowe:
- **Psychrometr Assmanna ($w_1$):** $$67.72 \% \pm 3.25 \%$$
- **Metoda tabelaryczna ($w_2$):** $$67.60 \%$$
- **Higrometr włosowy ($w_3$):** $$35 \% \pm 2.89 \%$$
- **Higrometr pojemnościowy ($w_4$):** $$30.5 \% \pm 1.44 \%$$
# Wnioski
- Wyniki dla higrometrów oraz psychrometru i tablic psychrometrycznych drastycznie się od siebie różnią. Higrometr włosowy wskazywał 35%, pojemnościowy 30.5% podczas, gdy psychrometr Assmana wskazał 67.72%, a tablica psychrometryczna pokazała 67.60%.
- Takie rozbieżności mogą wynikać z niedoskonałości przyrządów. Mówimy wtedy o błędzie systematycznym.
- Należy mieć na uwadze, że ekran higrometru pojemnościowego był uszkodzony i mogło to wpłynąć na poprawny odczyt wilgotności powietrza.
- Higrometr włosowy mógł być rozkalibrowany co wpłynęło negatywnie na wynik.