- Matlab, ale jak ktoś umie to może być dowolny język

# Treść
- Rachunek błędów
- Równania liniowe
- Interpolacja funkcji
- Aproksymacja funkcji

# Numeryczna reprezentacja liczb
Systemy liczbowe i konwersja.

# Liczby maszynowe
Liczba maszynowa to wybrana liczba rzeczywista zapisana w wybranym systemie liczbowym.
Nie każda liczba rzeczywista jest liczbą maszynową.

Liczbę maszynową da się zapisać za pomocą sumy potęg liczby $2$.

Liczb niemaszynowych __nie da się__ zapisać na skończonej liczbie bitów. Operujemy wtedy na przybliżeniach.

Zbiór liczb maszynowych jest skończony i ograniczony architekturą procesora.

---

Liczby całkowite, zmiennoprzecinkowe, precyzja

Dlaczego Pani pokazuje nam kod w wordzie? A nie, to jednak mathlab.

Macierze, macierz diagonalna. górno/dolno trójkątna.

Normy wierszowe, normy kolumnowe.

Jakieś macierze, nwm o co chodzi za bardzo.

Metoda Doolittle'a, metoda podobna do eliminacji Gaussa.

Jeśli macierz jest rzeczywista, symetryczna, dodatnio określona, to ma ona jeden jedyny rozkład na czynniki $A =LL^T$ gdzie $L$ jest macierzą trójkątną dolną o elementach dodatnich na głównej przekątnej.

Rozkład LU: bierzemy macierz, przyrównujemy ją do macierzy $L * U$, a potem patrzymy z mnożenia co wychodzi i rozwiązujemy równania. 

Rozkład QR.

Układy równoważne: układ równań wynika z innego układu przez skończony ciąg operacji elementarnych.

# Rozwiązywanie równań liniowych
## Metody dokładne
- Wzory cramera.
- Eliminacja gaussa
- Eliminacji gaussa-crouta

Na zaliczeniu nie będzie eliminacji gaussa.
Czym się różni pełna od częściowej? Jakie dwa etapy. Co jak natrafimy na $0$?
Takie rzeczy na zaliczeniu.

Rozkład QR i LU będzie na zaliczeniu.

## Metody przybliżone (iteracyjne)
- metody kaczmarza
- metoda richardsona
- metoda jaccobiego
- matoda gausa-seidela

 - przybliżone obliczenia
 - zatrzymują się przy osiągnięciu tolerancji błędu
 - rozwiązanie zawsze obarczone błędem
 - im gorzej uwarunkowana macierz tym gorsze rozwiązanie
 - stabilne
 - błędy zaokgrągleń są minimalizowane w kolejnych iteracjach
 - szybsze niż metody dokładne