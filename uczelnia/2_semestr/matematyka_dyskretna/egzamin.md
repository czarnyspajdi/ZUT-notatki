# Logika
- Prawo de'morgana – przy negacji alternatywy lub koniunkcji zamieniamy też ze sobą działania 
- suma indeksowanej rodziny zbiorów – elementy które występują w co najmniej jednym
- iloczyn indeksowanej rodziny zbiorów – elementy które wystęupją w każdym
# Abstrakcja
- Izomorfizm – bijekcja, która zachowuje funkcje i relacje.
- Homomorfizm – odwzorowanie jednej algebry liniowej(np. pierścienia) w drugą przy zachowaniu odpowiednich działań
- Automorfizm – izomorfizm na samym sobie, czyli odwzorowanie struktury na samą siebie przy zachowaniu działań itp.

# Relacje
- piwo z kolegami
- zwrotność (każda ze sobą)
- symetryczność (działa w dwie strony)
- przechodniość (jeśli xRy i yRz to xRz)
- relacja równoważności, gdy spełnia wszystko powyżej 
- antysymetryczność (xRy i yRx wtedy i tylko wtedy gdy x = y)
# Struktury
- Grupa – struktura algebraiczna definiowana jako zbiór z określonym na nim łącznym i odwracalnym dwuargumentowym działaniem wewnętrznym[1]; szczególny przypadek monoidu, w którym każdy element ma element odwrotny (zob. Podobne struktury).
- Iniekcja – każdy argument ma przypisaną tylko jedną wartość i żadne dwa argumenty nie dają tej samej wartości. Innymi słowy jest różnowartościowa.
- Suriekcja – zbiór wartości pokrywa się z przeciwdziedziną (każdy element przeciwdziedziny jest użyty)
- Bijekcja – iniekcja i suriekcja na raz. Liczba bijekcji to $n!$ gdzie n to ilość el. zbioru.

- działanie wewnętrzne – operacjie nie wyrzucają nas z danego zbioru
- rozdzielność $a \cdot (b + c) = (a \cdot b) + (a \cdot c)$ 
- półgrupa – nie potrzebuje el. neutralnego i odwrotnego
# Grafy
- Graf – podstawowy obiekt rozważań teorii grafów, struktura matematyczna służąca do przedstawiania i badania relacji między obiektami. W uproszczeniu graf to zbiór wierzchołków, które mogą być połączone krawędziami w taki sposób, że każda krawędź kończy się i zaczyna w którymś z wierzchołków.

- Graf planarny – graf który można narysować nie przecinając linii na kartce. 
- Graf spójny – każda para wierzchołków jest połączona

- Twierdzenie Kuratowskiego – graf jest planarny, jeśli nie zawiera podgrafu, który jest grafem rozszerzonym grafu $K_5$ lub $K_{3,3}$. Innymi słowy: graf jest planarny jeśli nie jest stworzony z pentagramu/3 kropek na góra-dół.
- Macierz incydencji – pokazuje gdzie wierzchołki grafu mają krawędzi. Wiersz to wierzchołek, a kolumny to krawędzi. Jeśli jest $0$ to nie styka się, jeśli liczba $< 0$ to wchodzi do wierzchołka, a jeśli $> 0$ to z niego wychodzi.  

# Teoria liczb
- $ax + by = c$, przy takim zapisie szukamy $NWD(a, b)$ i sprawdzamy czy dzieli liczbę c. Uzywamy rozszerzonego algorytmu Euklidesa
- Hinolskie twierdzenie o resztach służy do rozwiązywania układów równań.
Ważne wzory:
$$
\begin{align}
N &= n_i \cdot n_{i + 1} \cdot \ ...\  \cdot n_k \\
N_i &= \frac{N}{n_i} \\
N_i \cdot y_i &\equiv 1 \pmod{n_i} \\
x &= \sum_{i = 1}^{k}({a_i \cdot N_i \cdot y_i}) \pmod{N}
\end{align}
$$

# Euklides
Mamy NWD(a,b), gdzie a > b
1. Rozpisujemy a za pomocą b $a = b \cdot x + r$, gdzie x to wielokrotność a r reszta
2. rozpisujemy b za pomocą r 
3. powtórz, aż dojdziesz do momentu gdy $r = 0$

Rozszerzenie polega na robieniu tego samego ale w drugą stronę