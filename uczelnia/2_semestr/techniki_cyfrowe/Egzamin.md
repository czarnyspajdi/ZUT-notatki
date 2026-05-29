# Logika
## Opis formalny

Pierwszy i kluczowy krok w metodyce projektowania układów cyfrowych, pozwalający na przekształcenie problemu opisanego słownie (np. projektowania układu do głosowania dla kilku użytkowników) w ścisły model matematyczny.

- $\cdot$ koniunkcja  
- $+$ alternatywa
## Zmienne wejściowe
To nazwy symboliczne reprezentujące fizyczne sygnały wejściowe.
## Tablica prawdy
Tabela o liczbie wierszy $2^n$, gdzie $n$ jest liczbą zmiennych (literałów).
Pokazuje wszystkie możliwe kombinacje wartości logicznych zmiennych.
## Termy
| **Nr** | **c** | **b** | **a** | **Wyjście d** | **Iloczyny elementarne**                             |
| ------ | ----- | ----- | ----- | ------------- | ---------------------------------------------------- |
| 0      | 0     | 0     | 0     | 0             | $\overline{c} \cdot \overline{b} \cdot \overline{a}$ |
| 1      | 0     | 0     | 1     | 0             | $\overline{c} \cdot \overline{b} \cdot a$            |
| 3      | 0     | 1     | 1     | 1             | $\overline{c} \cdot b \cdot a$                       |
| 2      | 0     | 1     | 0     | 0             | $\overline{c} \cdot b \cdot \overline{a}$            |
| 6      | 1     | 1     | 0     | 1             | $c \cdot b \cdot \overline{a}$                       |
| 7      | 1     | 1     | 1     | 1             | $c \cdot b \cdot a$                                  |
| 5      | 1     | 0     | 1     | 1             | $c \cdot \overline{b} \cdot a$                       |
| 4      | 1     | 0     | 0     | 0             | $c \cdot \overline{b} \cdot \overline{a}$            |
### Maxterm
[Źródło](https://pl.wikipedia.org/wiki/Maksterm)
Maxterm to term składający się z literałów połączonych symbolem alternatywy.  Dokładnie dla jednej kombinacji wejść przyjmuje 0.
![](../../../media/Pasted%20image%2020260529204333.png)
Kanoniczna postać iloczynu opiera się na maxtermach.
### Minterm
[Źródło](https://pl.wikipedia.org/wiki/Minterm)
Minterm to term składający się z literałów połączonych symbolem koniunkcji. Dokładnie dla jednej kombinacji wejść przyjmuje 1.
![](../../../media/Pasted%20image%2020260529204254.png)
Kanoniczna postać sumy jest tworzona za pomocą mintermów.

## Implikant
- Implikant funkcji – term iloczynowy w funkcji logicznej wyrażonej w postaci sumy iloczynów, których wartość wynosi „1”. Wartość funkcji wynosi „1” jeśli wartość implikantu wynosi „1” (Implikant implikuje jedynkę funkcji) 
- Implikant prosty – taki implikant, z którego usunięcie dowolnego literału powoduje, że iloczyn przestaje być implikantem 
- Implikant istotny – jeśli minterm funkcji zawarty jest tylko w jednym implikancie prostym
## Implicent
[Źródło](https://pl.wikipedia.org/wiki/Implicent)
Taki maksterm lub iloczyn makstermów, że funkcja przyjmuje wartość 0, gdy jego wartość wynosi 0.
- Implicent funkcji – term sumacyjny w funkcji logicznej wyrażonej w postaci iloczynu sum, których wartość wynosi „0”. Wartość funkcji wynosi „0” jeśli wartość implicentu wynosi „0” (Implicent wymusza zero funkcji) 
- Implicent prosty – taki implicent, z którego usunięcie dowolnego literału powoduje, że suma przestaje być implicentem 
- Implicent istotny – jeśli maksterm funkcji zawarty jest tylko w jednym implicencie prostym
## Metody minimalizacji funkcji logicznych
### Prawami logicznymi
1. Rysujemy 2 tablice prawdy.
2. Dopisujemy kolumnę z min/max termami. Mintermy to te z mnożeniem, a maxtermy z plusem.
3. Bierzemy pod uwagę wszystkie te maxtermy, gdzie wartość wychodzi 0 i mintermy, gdzie wartość wychodzi 1.
4. Zapisujemy to jako y = [min/maxtermy]. Oczywiście jeśli mam mintermy to grupy ze sobą dodajemy, a maxtermy to grupy ze sobą mnożymy. 
5. Za pomocą zasad takich jak rozdzielność, rozłączność itp. możemy uprościć taki wzorek.

### Tablica Karnaugh
Dwuwymiarowa tablica prawdy zgodna z kodem greya. Tzn, że w każdym kolejnym wierszu/kolumnie zmienia się maksymalnie 1 bit na raz. Należy zachować odpowiednią kolejność przy wypełnianiu tablicy. Nie będę się tu o tym rozpisywał, bo dużo było na labach.


