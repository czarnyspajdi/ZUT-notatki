# Węzły
Węzły interpolacyjne to inaczej nazwane punkty przez które przechodzi interpolowana funkcja. Żeby możliwe było znalezienie rozwiązania takiego zadania w każdym węźle koordynat X musi być różny.

# [Efekt Rungego](https://pl.wikipedia.org/wiki/Efekt_Rungego)
Efekt rungego polega na pogorszeniu się jakości interpolacji pomimo zwiększenia liczby węzłów (punktów). Początkowo im więcej węzłów tym lepsze przybliżenie, ale od pewnego momentu zaczyna się pogarszać, co widać szczególnie na krańcach przedziałów. To zachowanie dotyczy [interpolacji wielomianowej]. Aby to zjawisko wystąpiło muszą być spełnione dwie przesłanki:
- wysoki stopień wielomianu
- równa odległość pomiędzy węzłami interpolacyjnymi

# [Macierz Vandermonda](https://pl.wikipedia.org/wiki/Macierz_Vandermonde%E2%80%99a)
Taka macierz:
$$
A = \left(\begin{matrix}
1 & 1 & 1 & 1 \\
1 & 2 & 4 & 8 \\
1 & 3 & 9 & 27 \\
1 & 4 & 16 & 64
\end{matrix}\right)
$$

Albo bardziej ogólnie:
$$
A = \left(\begin{matrix}
1 & x_1 & x^2_1 & \cdots & x^{n-1}_1 \\
1 & x_2 & x^2_2 & \cdots & x^{n-1}_2 \\
\vdots & \vdots & \vdots & \ddots & \vdots \\
1 & x_n & x^2_n & \cdots & x^{n-1}_n
\end{matrix}\right)
$$
Wyznacznik tej macierzy to specjalny **wyznacznik Vandermonde'a** i jest zapisywany w postaci:
$$
\det A = \prod_{1 \leqslant i<j \leqslant n} (x_j-x_i).
$$
# [Punkt stacjonarny](https://pl.wikipedia.org/wiki/Punkt_stacjonarny)
Zwany również punktem krytycznym, punkt w dziedzinie funkcji rzeczywistej, w którym pierwsza pochodna przyjmuje wartość zero. W tym punkcie oryginalna funkcja oczywiście zmienia kierunek.
Jeśli w tym punkcie istnieje druga pochodna, to punkt ten jest ekstremum lokalnym lub punktem przegięcia (przegioles pale). 
Dla funkcji wielu zmiennych w punkcie krytycznym zerują sie pochodne cząstkowe.

# [Gradient](https://pl.wikipedia.org/wiki/Gradient_(matematyka))
Wektor, który wskazuje gdzie funkcja rośnie. Długość wektora mówi nam o ile wzrasta funkcja na jednostkę długości.
uno dos tres quanto sinco sinco ses

[Wyznaczanie gradientu](https://youtu.be/Pt-AJvGEPuA?si=Q2Gh7xz62cELr_8j&t=9)

Ogólnie rzecz ujmując sprowadza się do tego, żeby obliczyć pochodne po następnych zmiennych ($x, y, z$), a potem umieścić je w wektorze. Potem obliczyć wartość gradientu dla konkretnego punktu.

# Metoda częściowego wyboru elementu podstawowego
Rozwinięcie metody eliminacji Gausaa, które polega na znalezieniem najlepszego kandydata do eliminowania kolumn przed rozpoczęciem całej procedury. 
- Będąc w k-tym kroku eliminacji wybieramy k-tą kolumnę i szukamy maksimum po module poniżej głównej przekątnej włącznie.
- Ten wiersz gdzie znaleźliśmy nową liczbę zamieniamy z k-tym wierszem.
Dzięki temu nie dzielimy przez zero jak debil i pomniejszamy błędy wynikające z zaokrągleń wyników dzielenia małych liczb.

# [Metoda Newtona](https://pl.wikipedia.org/wiki/Metoda_Newtona)
Zwana również metodą stycznych polega na tym, że się styka ten teges. Proste i logiczne.

Algorytm prowadzi do znalezienia przybliżonej wartości miejsca zerowego funkcji jednej  lub wielu zmiennych.

Jeżeli w przedziale znajduje się 1 pierwiastek funkcji, krańce mają różne znaki, pierwsza i druga mają stały znak w przedziale to wybieramy dowolny kraniec przedziału, wyznaczamy styczną do wykresu funkcji w tym punkcie, wyznaczamy odciętą punktu przecięcia stycznej z osią OX – odcięta jest drugim przybliżeniem szukanego rozwiązania. Nową wartość przyjmujemy jako startową i tak powstaje perpetum debile.

Metodę te można uogólnić do przypadku wielowymiarowej. Wtedy ponownie wybieramy punkt startowy, a następnie rekurencyjnie przekształcamy wektor jedynek lub zerowy, aż do momentu satysfakcjonującego nas przybliżenia. Wektor ma tyle kolumn/wierszy co liczba zmiennych w wielomianie.Przkształcamy wektor zgodnie z równaniem macierzowym:
$$
x_{k+1} = x_K - (F'(x_k))^{-1} F(x_k)
$$
Gdzie $F'(x_K)$ to macierz Jacobiego. Zawiera wszystkie możliwe pochodne cząstkowe pierwszego rzędu. $F(x_K)$ to  wektor wartości rozwiązań wszystkich równań dla aktualnego punktu.

Kończymy liczyć, gdy osiągniemy wystaczające przybliżenie, czyli wartość jest mniejsza niz epsilon.

# Wielomian interpolacyjny w postaci Newtona
Jak to gówno zbudować?
1. Bierzemy punkty np. 
$$
\begin{align}
(x_o, y_0) \\
(x_1, y_1) \\
(x_2, y_2)
\end{align} 
$$
2. Wykonujemy działania
$$
\begin{align}
I_1 &= \frac{y_0 - y_1}{x_0 - x_1} \\
I_2 &= \frac{y_2 - y_1}{x_2 - x_1} \\
I_3 &= \frac{I_2 - I_1}{x_2 - x_0} \\
\end{align}
$$
3. Podstawiamy:
$$
W(x) = y_0 + I_1(x - x_0) + I_3(x - x_0)(x - x_1) +…
$$
Tablica ilorazów różnicowych

| $x_i$     | $f(x_i)$ | $I_1$         | $I_2$              | $I_3$                   |     |
| --------- | -------- | ------------- | ------------------ | ----------------------- | --- |
| $x_0$<br> | $f(x_0)$ | $f[x_0, x_1]$ | $f[x_0, x_1, x_2]$ | $f[x_0, x_1, x_2, x_3]$ |     |
| $x_1$     | $f(x_1)$ | $f[x_1, x_2]$ | $f[x_1, x_2, x_3]$ |                         |     |
| ...       |          |               |                    |                         |     |
Czyli dla przykładu:
x: $-3\ 1\ 3$
f(x) $8\ 16\ 24$

| -3            | 8   | $\frac{8}{4} = 2$ | $\frac{1}{3}$ |
| ------------- | --- | ----------------- | ------------- |
| 1             | 16  | $\frac{8}{2} = 4$ |               |
| 3             | 24  |                   |               |
|               |     |                   |               |
| Współczynniki | 8   | 2                 | $\frac{1}{3}$ |
$W(x) = 8 + 2(x + 3) + \frac{1}{3}(x + 3)(x - 1)$

# [Hesjan](https://pl.wikipedia.org/wiki/Macierz_Hessego)
Elitarna macierz drugich pochodnych cząstkowych fla funkcji wielu zmiennych o wartościach rzeczywistych dwukrotnie różniczkowalnych w punkcie, w którym liczone są te pochodne.
Cała ta macierz opisuje własności krzywizny wykresu funkcji w otoczeniu punktu. Jest wyznaczana np. w punktach krytycznych przy wyszukiwaniu ekstremów i punktów przegięcia (przegioles). 
Macierz ta jest kwadratowa.

Buduje się ją w sposób następujący:
Musimy policzyć wszytkie możliwe pochodne drugiego stopnia. Po x, po xy, po xz, po z, po zx, itp, itd. Potem układamy to tak:
- po przekątnej pochodne po jednej zmiennej
- w kolumnach ustawiamy pochodne po kolejnych zmiennych
- w rzędach zmieniamy naszą pojedyńczą zmienną pochodną

# [Wersor](https://pl.wikipedia.org/wiki/Wektor_jednostkowy)
Wektor jednostkowy o długości jeden. Wskazuje kierunek i zwrot pewnego wektora początkowego, któremu ten wersor się przypisuje. Każdy wektor można zamienić na wersor (znormalizować) dzieląc go przez jego długość.
![](../../../media/Pasted%20image%2020260617124924.png)


# [Aproksymacja sześcienna]
POlega na przykładaniu funkcje szcześciennej do wykresu. Jako punktów uzywa wartości funkcji i jej pochodnych. żeby to było możliwe to oczywiście musi być na krańcach przedzialu pochodna wymnożona na minusie tego typu
# Wyznaczniki macierzy trójkątnych i diagonalnych
Oblicza się je mnożąć przez siebie wszytkie liczby leżące na głównej przekątnej.
Macierz diagonalna – ma liczby tylko na przekątnej.
Macierz trójkątna górna –» ma zera pod główną przekątną.
# [Metoda falsi](https://pl.wikipedia.org/wiki/Regula_falsi)
Falsi z nazwy metody oznacza oczywiście, że jest do dupy.

Bierzemy jeden punkt powyżej zera, drugi jest poniżej. Rysujemy prostą (falsi[znaną również pod nazwą prosta sraka]). Tam gdzie sraka przechodzi przez oś OX  liczymy wartość funkcji. Zamieniamy to na ten poprzedni punkt. Powtarzamy, aż osiągniemy dokładność.
# [Metoda Powella](http://www.optymalizacja.w8.pl/Powella.html)
Metoda bezgradientowa, która wykorzystuje wersor.

Mamy dwa wektory (kierunki) $d_i$ i $d_j$. Nazywamy je sprzężonymi względem kwadratowej dodatnio określonej macierzy H jeśli:
$$
d_i^T \cdot H d_i = 0 \ \text {dla } i \neq j
$$
# [Metoda najszybszego spadku](https://pl.wikipedia.org/wiki/Metoda_najszybszego_spadku)
Metoda gradientowa.
$$
\begin{align}
P_{k + 1} &= P_K - \alpha_k \nabla_k \\
\text{gdzie:}
\alpha_k &= \frac{\nabla_k^T \nabla_k}{\nabla_K^T H_k \nabla_K}
\end{align}
$$
Co to dokładnie oznacza? Każdy kolejny krok to aktualny krok minus gradient razy krok. A krok $\alpha$ to transponowany gradient razy gradient podzielone przez transponowany gradient razy gradient razy hesjan.

Problemem tej metody jest to, że potrafi zwolni i zyzgakować, jeśli funkcja ma kształt wąskiej, ukośnej doliny. Żeby temu zapobiec:
- wprowadza się nowe kierunki za pomocą $\Delta = P_{k + 1} - P_K$
- obraca układ współrzędnych, by jedna z osi pokrywała się z dnem.

# Warunek przy szukaniu pierwiastków równań nieliniowych
$f(a) \cdot f(b) < 0$
W komputerach może występować zjawisko niedomiaru, które wynika z zaokrągleń do zera przy bardzo niskich wartościach. Aby temu zapobiec robi się taki myk:
```matlab
sign(f(a)) != sign(f(b))
```


# [Metoda połowienia](https://pl.wikipedia.org/wiki/Metoda_r%C3%B3wnego_podzia%C5%82u)
Algorytm poszukiwania pierwiastka funkcji.

Metoda polega na dzieleniu przedziału na pół, a następnie odrzucaniu podprzedziału, w którym dwa jego krańce nie zmieniają znaku.
# [Metoda złotego podziału](https://pl.wikipedia.org/wiki/Metoda_z%C5%82otego_podzia%C5%82u)
Metoda optymalizacji jednowymiarowej funkcji celu.

Polega na wybraniu dwóch punktów, które wyznaczane tak, by dzieliły aktualny przedział w proporcji złotego podziału ( $61.8\%$) Wybieramy punkt, który jest niżej, aż osiągniemy zadaną dokładność $\epsilon$. Wtedy bierzemy środek tego przedziału i *beng* mamy minimum!

# [Simplex](https://pl.wikipedia.org/wiki/Algorytm_sympleksowy)
## Jak to liczyć?
1. Mamy układ równań, przekształcamy go w taki sposób, by po prawej stronie wszystkie wartości były dodatnie
$$
\begin{align*}
&f(x,y) = 7x + 2y - 3z \to \max \\
&\text{ograniczenia:} 
\end{align*}
$$
$$
\begin{align*}
\begin{cases}
2x + y - 3z &= 12 \\
5x - 3y + z &\geqslant 15 \\
-x + 2y &\geqslant -1 \implies x - 2y \leqslant 1
\end{cases}
\end{align*}
$$
2. Zamieniamy układ w taki sposób, by wyeliminować wszystkie symbole mniejsze/większe niż.  Żeby to zrobić musimy albo odjąć albo dodać jakąś liczbę. Jeżeli mam więcej niż to musimy odjąć i analogicznie.
$$
\begin{align}
\begin{cases}
2x + y - 3z &= 12 \\
5x - 3y + z - S_1 &= 15 \\
-x + 2y + S_2 &= 1
\end{cases}
\end{align}
$$
3. Zapisujemy funkcję celu
$$
f(x, y, z, S_1, S_2) = 7x + 2y -3z + 0S_1 + 0S_2
$$
4. Sprawdzamy czy mamy macierz jednostkową, czyli czy mamy kwadrat 3x3 w którym w każdej kolumnie jest jedna jedynka i jest ona w różnych wierszach. W tym przypadku pasuje nam tylko $S_2$, więc dodajemy zmienne sztuczne.
$$
\begin{align}
\begin{cases}
2x + y -3z + a_1 &= 12 \\
5x - 3y + z - S_1 + a_2 &= 15 \\
x - 2y + S_2 &= 1
\end{cases}
\end{align}
$$

Macierz jednostkowa
![](../../../media/Pasted%20image%2020260616200137.png)

5. Dodajemy albo bardzo dużo zmiennych sztucznych albo bardzo mało. Jeśli szukamy max to muszą być ujemne i analogicznie.
$$
f(x, y, z, S_1, S_2) = 7x + 2y -3z + 0S_1 + 0S_2 - 1000a_1 - 1000a_2
$$
6. Przechodzimy do uzupełniania tabelki
- 1. W $Cj\rightarrow$ wpisujemy ilość następnych zmiennych.
- 2.Wiersz pod tym wpisujemy co to są za zmienne.
- 3. Pod $B\downarrow$ (bazowa) wpisujemy wyrazy wolne po przekształceniach.
- 4. Pod $WB\downarrow$(wektory bazowe) wpisujemy nasze nowe sztuczne zmienne, które tworzą naszą macierz jednostkową.
- 5. Pod $CB\downarrow$ wpisujemy ile mamy tych zmiennych.
- 6. Uzupełniamy środek tabelki wartościami z układu równań dla poszczególnych zmiennych
- 7. $WW\rightarrow$(wiersz wskaźnikowy) uzupełniamy poprzez wymnożenie wartości z kolumny CB razy poszczególne kolumny zmiennych. Np. $-1000 \cdot 12 + (-1000) \cdot 15 + 0 \cdot 1 = -27000$ . Potem od wyniku odejmujemy wartość funkcji celu. Czyli np dla kolumny $x$ wykonujemy działanie $-7000 - 7 = -7007$

|                |                 | Cj$\rightarrow$ | 7     | 2    | -3   | 0     | 0     | -1000 | -1000 |                    |
| -------------- | --------------- | --------------- | ----- | ---- | ---- | ----- | ----- | ----- | ----- | ------------------ |
| CB$\downarrow$ | WB $\downarrow$ | B $\downarrow$  | x     | y    | z    | $S_1$ | $S_2$ | $a_1$ | $a_2$ | $\frac{B}{x}$      |
| -1000          | $a_1$           | 12              | 2     | 1    | -3   | 0     | 0     | 1     | 0     | $\frac{12}{2} = 6$ |
| -1000          | $a_2$           | 15              | 5     | -3   | 1    | -1    | 0     | 0     | 1     | $\frac{15}{5} = 3$ |
| 0              | $S_2$           | 1               | 1     | -2   | 0    | 0     | 1     | 0     | 0     | 1                  |
|                | $WW\rightarrow$ | -27000          | -7007 | 1998 | 2003 | 1000  | 0     | 0     | 0     |                    |

- 8. Gdy już mamy taką tabelkę szukamy wartość zmiennej wiersza wskaźnikowego, która jest najmniejsza. W tym przypadku będzie to zmienna $x$. Ta kolumna będzie kluczowa. 
- 9. Szukamy najmniejszej wartości w $\frac{B}{x}$. To będzie wiersz kluczowy.
- 10. Kolumna kluczowa wskazuje na wartość, która wchodzi do bazy, a wiersz kluczowy na wartość, która wylatuje.
- 11. Wartość na przecięciu się kolumny i wiersza kluczowego to pivot. Pivot musi być 1, a jeśli nie jest to mnożymy wiersz razy tyle, żeby był.
- 12. Używamy pivota, żeby zlikwidować liczbę nad nim. Ma być zerem! (Podobnie jak w metodzie eliminacji gaussa)

- 13.(7) Ponownie liczymy wiersz wskaźnikowy.

|                |                 | Cj$\rightarrow$ | 7   | -2     | -3   | 0     | 0     | -1000 | -1000 |                    |
| -------------- | --------------- | --------------- | --- | ------ | ---- | ----- | ----- | ----- | ----- | ------------------ |
| CB$\downarrow$ | WB $\downarrow$ | B $\downarrow$  | x   | y      | z    | $S_1$ | $S_2$ | $a_1$ | $a_2$ | $\frac{B}{y}$      |
| -1000          | $a_1$           | 10              | 0   | 5      | -3   | 0     | -2    | 1     | 0     | $\frac{10}{5} = 2$ |
| -1000          | $a_2$           | 10              | 0   | 7      | 1    | -1    | -5    | 0     | 1     | $\frac{10}{7}$     |
| 7              | $x$             | 1               | 1   | 2      | 0    | 0     | 1     | 0     | 0     | $\frac{1}{-2}$     |
|                | $WW\rightarrow$ | -19993          | 0   | -12016 | 2003 | 1000  | 7007  | 0     | 0     |                    |
- 14.(8) szukamy najmniejszej wartości w WW. To jest kolumna kluczowa. Tutaj to będzie y
- 15. (9) wyliczamy $\frac{B}{x}$ i szukamy najmniejszej nieujemnej wartości. Wiersz kluczowy!
- 16. Powtarzamy te kroki, aż w WW nie będzie ujemnych wartości. Wtedy w kolumnie WB w WW będzie wartość optymalna funkcji celu. W kolumnie B znajdziemy wtedy wartości zmiennych funkcji, które wpływają na ten wynik. Gdybyśmy liczyli minimum to nie mogłoby być żadnych liczb dodatnich!

**Na egzaminie nie trzeba rysować drugiej tabelki!**