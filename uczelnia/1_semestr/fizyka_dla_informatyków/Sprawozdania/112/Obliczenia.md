## Materiał: Mosiądz
### 1. Dane pomiarowe i stałe
* **Pomiary długości $l_0$:** [0.4048, 0.4047, 0.4046] m
* **Odczyt czujnika $S$:** 0.00021 m
* **Temp. wrzenia $T_{wrz}$:** 99.71 $^\circ$C
* **Temp. otoczenia $T_0$:** 21.0 $^\circ$C
* **Dokładności przyrządów:**
    * Termometr: $\Delta T_0 = 1.0$ K
    * Tabela wrzenia: $\Delta T_{tab} = 0.01$ K
    * Suwmiarka: $\Delta l = 1e-05$ m
    * Czujnik: $\Delta S = 1e-05$ m

### 2. Obliczenia wielkości fizycznych
**a) Średnia długość początkowa:**
$$\overline{l}_0 = \frac{1.21410}{3} = 0.40470 \, m$$
**b) Różnica temperatur:**
$$\Delta T = T_{wrz} - T_0 = 99.71 - 21.0 = 78.71 \, K$$
**c) Wydłużenie bezwzględne:**
$$\Delta l = S_{końc} - S_{pocz} = 0.00021 - 0.0 = 0.00021 \, m$$
**d) Współczynnik rozszerzalności**
$$\alpha = \frac{0.00021}{0.40470 \cdot 78.71} = \mathbf{6.59 \cdot 10^{-6} \, K^{-1}}$$
### 3. Szczegółowa analiza niepewności
**a) Niepewności standardowe typu B:**
* Termometr: $u_B(T_0) = \frac{1.0}{\sqrt{3}} = 0.5774$ K
* Tabela wrzenia: $u_B(T_{wrz}) = \frac{0.01}{\sqrt{3}} = 0.0058$ K
* Suwmiarka: $u_B(l_0) = \frac{1e-05}{\sqrt{3}} = 0.0000058$ m
* Czujnik wydłużenia: $u_B(\Delta l) = \frac{1e-05}{\sqrt{3}} = 0.0000058$ m
**b) Niepewność różnicy temperatur:**
$$u(\Delta T) = \sqrt{u_B^2(T_{wrz}) + u_B^2(T_0)} = \sqrt{0.0058^2 + 0.5774^2} = 0.5774 \, K$$
**c) Niepewność typu A:**
$$u_A(l_0) = \sqrt{\frac{\sum (l_i - \overline{l})^2}{n(n-1)}} = 0.0000577 \, m$$
**d) Udziały niepewności:**
* Od wydłużenia: $(\frac{u(\Delta l)}{\Delta l})^2 = 7.56e-04$
* Od długości: $\frac{1}{l_0^2}(u_A^2 + u_B^2) = 2.06e-08$
* Od temperatury: $(\frac{u(\Delta T)}{\Delta T})^2 = 5.38e-05$
* **Suma pod pierwiastkiem:** $8.10e-04$
**e) Niepewność całkowita:**
$$u(\alpha) = \alpha \cdot \sqrt{0.0008} = 0.19 \cdot 10^{-6} \, K^{-1}$$

> **Zestawienie końcowe:**
> * **Wynik z pomiaru:** $\alpha = (6.59 \pm 0.19) \cdot 10^{-6} \, K^{-1}$
> * **Wartość tablicowa:** $\alpha_{tab} \approx 19 \cdot 10^{-6} \, K^{-1}$
> * **Błąd względny:**
>   $$\delta = \frac{|6.59 - 19.0|}{19.0} \cdot 100\% = \mathbf{65.3\%}$$

---
## Materiał: Glin
### 1. Dane pomiarowe i stałe
* **Pomiary długości $l_0$:** [0.4037, 0.4036, 0.4036] m
* **Odczyt czujnika $S$:** 0.0001 m
* **Temp. wrzenia $T_{wrz}$:** 99.71 $^\circ$C
* **Temp. otoczenia $T_0$:** 21.0 $^\circ$C
* **Dokładności przyrządów:**
    * Termometr: $\Delta T_0 = 1.0$ K
    * Tabela wrzenia: $\Delta T_{tab} = 0.01$ K
    * Suwmiarka: $\Delta l = 1e-05$ m
    * Czujnik: $\Delta S = 1e-05$ m

### 2. Obliczenia wielkości fizycznych
**a) Średnia długość początkowa:**
$$\overline{l}_0 = \frac{1.21090}{3} = 0.40363 \, m$$
**b) Różnica temperatur:**
$$\Delta T = T_{wrz} - T_0 = 99.71 - 21.0 = 78.71 \, K$$
**c) Wydłużenie bezwzględne:**
$$\Delta l = S_{końc} - S_{pocz} = 0.0001 - 0.0 = 0.00010 \, m$$
**d) Współczynnik rozszerzalności:**
$$\alpha = \frac{0.00010}{0.40363 \cdot 78.71} = \mathbf{3.15 \cdot 10^{-6} \, K^{-1}}$$
### 3. Szczegółowa analiza niepewności
**a) Niepewności standardowe typu B:**
* Termometr: $u_B(T_0) = \frac{1.0}{\sqrt{3}} = 0.5774$ K
* Tabela wrzenia: $u_B(T_{wrz}) = \frac{0.01}{\sqrt{3}} = 0.0058$ K
* Suwmiarka: $u_B(l_0) = \frac{1e-05}{\sqrt{3}} = 0.0000058$ m
* Czujnik wydłużenia: $u_B(\Delta l) = \frac{1e-05}{\sqrt{3}} = 0.0000058$ m
**b) Niepewność różnicy temperatur:**
$$u(\Delta T) = \sqrt{u_B^2(T_{wrz}) + u_B^2(T_0)} = \sqrt{0.0058^2 + 0.5774^2} = 0.5774 \, K$$
**c) Niepewność typu A:**
$$u_A(l_0) = \sqrt{\frac{\sum (l_i - \overline{l})^2}{n(n-1)}} = 0.0000333 \, m$$
**d) Udziały niepewności:**
* Od wydłużenia: $(\frac{u(\Delta l)}{\Delta l})^2 = 3.33e-03$
* Od długości: $\frac{1}{l_0^2}(u_A^2 + u_B^2) = 7.02e-09$
* Od temperatury: $(\frac{u(\Delta T)}{\Delta T})^2 = 5.38e-05$
* **Suma pod pierwiastkiem:** $3.39e-03$
**e) Niepewność całkowita:**
$$u(\alpha) = \alpha \cdot \sqrt{0.0034} = 0.18 \cdot 10^{-6} \, K^{-1}$$

> **Zestawienie końcowe:**
> * **Wynik z pomiaru:** $\alpha = (3.15 \pm 0.18) \cdot 10^{-6} \, K^{-1}$
> * **Wartość tablicowa:** $\alpha_{tab} \approx 25 \cdot 10^{-6} \, K^{-1}$
> * **Błąd względny:**
>   $$\delta = \frac{|3.15 - 25.0|}{25.0} \cdot 100\% = \mathbf{87.4\%}$$

---
## Materiał: Stal
### 1. Dane pomiarowe i stałe
* **Pomiary długości $l_0$:** [0.4052, 0.4052, 0.4052] m
* **Odczyt czujnika $S$:** 0.00031 m
* **Temp. wrzenia $T_{wrz}$:** 99.71 $^\circ$C
* **Temp. otoczenia $T_0$:** 21.0 $^\circ$C
* **Dokładności przyrządów:**
    * Termometr: $\Delta T_0 = 1.0$ K
    * Tabela wrzenia: $\Delta T_{tab} = 0.01$ K
    * Suwmiarka: $\Delta l = 1e-05$ m
    * Czujnik: $\Delta S = 1e-05$ m

### 2. Obliczenia wielkości fizycznych
**a) Średnia długość początkowa:**
$$\overline{l}_0 = \frac{1.21560}{3} = 0.40520 \, m$$
**b) Różnica temperatur:**
$$\Delta T = T_{wrz} - T_0 = 99.71 - 21.0 = 78.71 \, K$$
**c) Wydłużenie bezwzględne:**
$$\Delta l = S_{końc} - S_{pocz} = 0.00031 - 0.0 = 0.00031 \, m$$
**d) Współczynnik rozszerzalności:**
$$\alpha = \frac{0.00031}{0.40520 \cdot 78.71} = \mathbf{9.72 \cdot 10^{-6} \, K^{-1}}$$
### 3. Szczegółowa analiza niepewności
**a) Niepewności standardowe typu B:**
* Termometr: $u_B(T_0) = \frac{1.0}{\sqrt{3}} = 0.5774$ K
* Tabela wrzenia: $u_B(T_{wrz}) = \frac{0.01}{\sqrt{3}} = 0.0058$ K
* Suwmiarka: $u_B(l_0) = \frac{1e-05}{\sqrt{3}} = 0.0000058$ m
* Czujnik wydłużenia: $u_B(\Delta l) = \frac{1e-05}{\sqrt{3}} = 0.0000058$ m
**b) Niepewność różnicy temperatur:**
$$u(\Delta T) = \sqrt{u_B^2(T_{wrz}) + u_B^2(T_0)} = \sqrt{0.0058^2 + 0.5774^2} = 0.5774 \, K$$
**c) Niepewność typu A:**
Pomijalna

**d) Udziały niepewności:**
* Od wydłużenia: $(\frac{u(\Delta l)}{\Delta l})^2 = 3.47e-04$
* Od długości: $\frac{1}{l_0^2}(u_A^2 + u_B^2) = 2.03e-10$
* Od temperatury: $(\frac{u(\Delta T)}{\Delta T})^2 = 5.38e-05$
* **Suma pod pierwiastkiem:** $4.01e-04$
**e) Niepewność całkowita:**
$$u(\alpha) = \alpha \cdot \sqrt{0.0004} = 0.19 \cdot 10^{-6} \, K^{-1}$$

> **Zestawienie końcowe:**
> * **Wynik z pomiaru:** $\alpha = (9.72 \pm 0.19) \cdot 10^{-6} \, K^{-1}$
> * **Wartość tablicowa:** $\alpha_{tab} \approx 12 \cdot 10^{-6} \, K^{-1}$
> * **Błąd względny:**
>   $$\delta = \frac{|9.72 - 12.0|}{12.0} \cdot 100\% = \mathbf{19.0\%}$$

---

## 4. Wnioski

1.  Analiza wyników: Wyznaczone doświadczalnie wartości współczynników rozszerzalności liniowej obarczone są znacznym błędem względnym w porównaniu do danych tablicowych. W przypadku glinu i mosiądzu rozbieżności te są bardzo duże (rzędu 60–80%), co sugeruje wystąpienie błędów grubych podczas pomiaru.
2.  Błędy systematyczne (temperatura): Jedną z przyczyn niedokładności pomiaru mogło być niedostateczne wychłodzenie układu pomiarowego przed rozpoczęciem eksperymentu (niestabilna temperatura początkowa $t_0$). Jeśli temperatura początkowa pręta była wyższa od temperatury otoczenia przyjętej w obliczeniach, rzeczywista różnica temperatur $\Delta t$ była mniejsza, co wpłynęło na wynik końcowy.
3.  Weryfikacja błędu grubego (Glin): Analiza wyniku dla glinu (bardzo niska wartość wyznaczona) wskazuje na wysokie prawdopodobieństwo błędu odczytu na dylatometrze czujnikowym. Najbardziej prawdopodobną przyczyną jest wykonanie przez wskazówkę czujnika jednego pełnego, niezarejestrowanego obrotu przed finalnym odczytem. 