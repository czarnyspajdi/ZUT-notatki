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
### Przekształcenie prawami logicznymi
1. Rysujemy 2 tablice prawdy.
2. Dopisujemy kolumnę z min/max termami. Mintermy to te z mnożeniem, a maxtermy z plusem.
3. Bierzemy pod uwagę wszystkie te maxtermy, gdzie wartość wychodzi 0 i mintermy, gdzie wartość wychodzi 1.
4. Zapisujemy to jako y = [min/maxtermy]. Oczywiście jeśli mam mintermy to grupy ze sobą dodajemy, a maxtermy to grupy ze sobą mnożymy. 
5. Za pomocą zasad takich jak rozdzielność, rozłączność itp. możemy uprościć taki wzorek.

![](../../../media/Pasted%20image%2020260530180423.png)
W takiej sytuacji podstawiamy pod równanie odpowiednie  wartości zmiennych i wyliczamy y.

### Tablica Karnaugh
Dwuwymiarowa tablica prawdy zgodna z kodem greya. Tzn, że w każdym kolejnym wierszu/kolumnie zmienia się maksymalnie 1 bit na raz. Należy zachować odpowiednią kolejność przy wypełnianiu tablicy. Nie będę się tu o tym rozpisywał, bo dużo było na labach.

## Hazard
Zjawisko hazardu może występować na skutek optymalizacji logicznej układu. **Hazard polega na krótkotrwałych, fałszywych stanach logicznych  (tzw. szpilkach) na wyjściu układu kombinacyjnego, podczas procesów przejściowych.** Występuje, gdy co najmniej jeden sygnał jest przesyłany dwoma różnymi drogami prowadzącymi do jednej bramki. Np. mamy 2 różne sygnały, które idą do bramki AND, ale na drodze jednego z nich jest jeszcze odwracacz (inventer). 
### Hazard statyczny
Hazard opisany powyżej.
### Hazard dynamiczny
Występuje w układach wielopoziomowych.

## Multi/demultiplexery
### $n$ zmiennych
Za pomocą multiplexerów można wykonać każdą funkcję kombinacyjną. Aby to uczynić należy uzupełnić w równaniu każdy implikant do $n$ literałów.  Tak rozbudowane implikanty stają się adresami wejść informacyjnych układu. Realizacja sprzętowa polega na tym, że do wyznaczonych wejść informacyjnych multipleksera podłącza się fizycznie stały stan wysoki (Vcc, logikę „1”), natomiast wszystkie pozostałe, nieużywane wejścia zwiera się do masy (GND, logika „0”). Metodę tę można zrealizować także bezpośrednio na podstawie tablicy prawdy.
### $n - 1$ zmiennych
 Jest to podejście o wiele bardziej optymalne sprzętowo, ponieważ pozwala zrealizować tę samą funkcję na o połowę mniejszym multiplekserze. Pozostała, jedna zmienna (np. $x_0$​) nie trafia na wejścia adresowe, lecz jest wykorzystywana do sterowania wejściami informacyjnymi. Aby fizycznie zbudować taki układ, można postąpić na dwa sposoby:

- **Sposób 1 (na podstawie tablicy prawdy):** Przeprowadza się analizę tego, jak wyjście układu zachowuje się względem tej jednej wyizolowanej zmiennej (x0​) przy poszczególnych stanach pozostałych wejść adresowych. W efekcie do konkretnych wejść informacyjnych multipleksera podłącza się: stałą „1”, stałe „0”, połączoną bezpośrednio zmienną x0​, lub zmienną x0​ przepuszczoną przez dodatkowy inwerter logiczny (bramkę NOT).
- **Sposób 2 (przez przekształcenie wyrażenia logicznego):** Równanie funkcji należy przekształcić matematycznie tak, aby każdy implikant zawierał literały wybrane jako zmienne dołączane do wejść adresowych multipleksera. Po takim pogrupowaniu zmiennych, jeśli implikant bazuje tylko na zmiennych adresowych, do odpowiadającego wejścia informacyjnego podłącza się stałą „1”. Jeżeli w implikancie zostaje "reszta" pod postacią wyizolowanej zmiennej x0​ (w postaci prostej lub zanegowanej), to fizycznie doprowadza się ten sygnał wejściowy do danego wejścia. Ostatnim krokiem jest dołączenie logicznego „0” do wszystkich nieużytych wejść informacyjnych

# Technologie
## Układy scalone (Integrated Circuits – IC)
### Bipolarne
TTL – transistor-transistor logic
ECL – Emitter-Coupled Logic

Rozwiązania zanikające
### Unipolarne
Np. MOS i CMOS.

Mniejsza moc strat i możliwość budowania układów o ogromnym stopniu scalenia, takich jak VLSI lub ULSI

