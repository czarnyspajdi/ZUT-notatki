# Spis tematów
Oto uporządkowana lista tematów, które pojawiają się w przesłanych przez Ciebie notatkach. Zostały one pogrupowane w logiczne kategorie:

**1. Podstawy rachunku prawdopodobieństwa i zdarzenia losowe**

- Przestrzeń zdarzeń elementarnych (Ω) i pojedyncze zdarzenia elementarne (ω)
    
- Zbiory przeliczalne
    
- Działania na zbiorach i zdarzeniach (dopełnienie, suma, przekrój)
    
- Zdarzenie niemożliwe i zdarzenia wykluczające się
    
- Przestrzenie mierzalne i zbiory borelowskie
    

**2. Definicje i miary prawdopodobieństwa**

- Klasyczna definicja prawdopodobieństwa (Laplace'a) dla przestrzeni skończonych
    
- Miara Lebesgue'a (odnosząca się do długości, pola i objętości)
    
- Prawdopodobieństwo geometryczne i pojęcie miary bezatomowej
    

**3. Zmienna losowa i statystyka opisowa (charakterystyki zmiennej)**

- Definicja zmiennej losowej jako funkcji
    
- Dystrybuanta i jej własności (ciągłość, granice w nieskończoności)
    
- Miary rozproszenia: Wariancja, odchylenie standardowe (σ) i współczynnik zmienności
    
- Miary położenia: Kwantyle, mediana, kwartyle, centyle (oraz ich praktyczne zastosowanie, np. do mierzenia długości dziecka)
    
- Miary asymetrii rozkładu (np. wydłużony ogon, na przykładzie rozkładu płac)
    
- Wartości skrajne (konieczność ich odrzucania przy pomiarach)
    
- Dominanta (moda)
    

**4. Rozkłady prawdopodobieństwa**

- **Rozkłady dyskretne (skokowe):**
    
    - Rozkład zero-jedynkowy (0-1)
        
    - Rozkład dwumianowy (wzmianka o trójkącie Pascala)
        
    - Rozkład geometryczny (ciąg geometryczny z parametrami _p_ i _q_)
        
    - Rozkład Poissona
        
- **Zmienne i rozkłady typu ciągłego:**
    
    - Związek dystrybuanty z całką (pole pod wykresem)
        
    - Rozkład wykładniczy
        
    - Rozkład normalny (funkcja Gaussa)
        

**5. Wektory losowe i zagadnienia zaawansowane**

- Niezależność zmiennych losowych
    
- Wektory losowe (w tym wektory typu skokowego) i ich dystrybuanty
    
- Charakterystyki wektora losowego
    
- Twierdzenia graniczne (jako temat zamykający)

# Zdarzenia losowe
## Jak wygląda przestrzeń zdarzeń elementarnych?
zdarzenie – $\omega$ 
przestrzeń zdarzeń – $\Omega$

## Co to jest zbiór przeliczalny 
Zbiór, który da się ponumerować
Dopełnienie zbioru jest też jego elementem.

## Co to jest zdarzenie elementarne?
Dowolne $A$ należące do $Z$ to zdarzenie losowe.

Dopełnienie i suma jest też zdarzeniem losowym.

## Zdarzenie niemożliwe
Zbiór pusty

Zdarzenia których przekrój jest pusty wykluczają się.

# Przykłady przestrzeni mierzalnych
Zbiory borelowskie to rodzina wszystkich przedziałów ograniczonych otwartych (najmniejsza klasa zdarzeń losowych zawierających rodzinę $\epsilon$)

# Definicja prawdopodobieństwa
Prawdopodobieństwo — probabilistyka

# Definicja Laplace'a
$\Omega$ — skończony, definicja Laplace'a

Jeżeli prawdopodobieństwo wszystkich zdarzeń elementarnych jest jednakowe to $P({\omega_n})  = \frac{1}{n}$ 

# Miara Lebesgue'a (lebega) m
Na prostej — długość
Na płaszczyźnie — pole
W przestrzeni — objętosć

Prawdopodobieństwo geometryczne.

Jeśli m jest miarą Lebesgue'a to można policzyć pole.

**Uwaga** miara bezatomowa, czyli dla pojedyńczych punktów = $0$

# Zmienna losowa
Funkcja, która zdarzeniom przypisuje liczbę!
Przekształca zdarzenia na zdarzenia.
(cokolwiek to znaczy)

Jeśli zbiór jest przeliczalny to każda funkcja jest zmienną losową.

## Dystrybuanta 
Coś tam, funkcją jest, jestem głodny

Funkcja prawostronnie ciągła.

W -∞ jest zerem, a w +∞ jest 1.

# Wariancja
Wariancja X to liczba. (czemu te definicje są takie nieludzkie)

Odchylanie standardowe to pierwiastek z wariancji. Oznaczana małą literką sigma $\sigma$.

Współczynnik zmienności mierzy odchylenie standardowe względem morbiusa.

Kwantyl rzędu p to jakaś liczba pomiędzy granicą funkcji a jej wartością (?)

Jak podaje [wikipedia](https://pl.wikipedia.org/wiki/Kwantyl):
> Kwantyle to punkty odcięcia dzielące zakres rozkładu prawdopodobieństwa na ciągłe przedziały o równych prawdopodobieństwach lub dzielące obserwacje w próbie w ten sam sposób.

## Mediana
Wartość najbardziej po środku

## Kwartyle
To kwantyl rzędu $0.25, 0.5, 0.75$.
Kwantyl $0.5$ to mediana.

## Centyle setyle dupyle
itp można tak dzielić

### Długość dziecka
Kwantylami można zmierzyć długość dziecka, bo dzięki temu można zapobiec różnym problemom.

# Inne charakterystyki zmiennej losowej
Miary mierzące asymetrię rozkładu.

Mamy wydłużony ogon po lewej stronie.

## Rozkład płac
Większość ludzie zarabia średnią, a nieliczone jednostki zarabiają dużo.

Przy robieniu pomiaru należy odrzucić jednostki skrajne.

## Dominanta
Moda, czyli coś co ma duże prawdopodobieństwo.

# Rozkład

## 0-1
| $x_1$<br> | 0   | 1   |
| --------- | --- | --- |
| $p_1$     | q   | p   |
Nie wiem o co chodzi.


## Rozkład dwumianowy
Kombinacje tworzą trójkąt pascala chyba czy coś?

## Rozkład geometryczny
Mamy tylko parametr P, zmienna losowa X przyjmuje K.
Sumujemy ciąg geometryczny o ilorazie q.

## Rozkład poissona
Trujący chyba

### Zmienne typu ciągłego
Wartość dystrybuanty w punkcie x to jest całka, bo to pole pod wykresem.

## Rozkład wykladniczy
Funkcja gaussa.

# Wektory losowe i niezależność zmiennych losowych

Dystrybuanta wektora losowego

Wektor losowy typu skokowego

# Charakterystyki wektora losowego centralne, twierdzenia graniczne i elementy statystyki opisowej
Ostatni temat z prawdopodobieństwa.

Zmienne dwuwymiarowe.

Kowariancja jest symetryczna

Kowariancja to miara określające siłę oraz zależność dwóch zmiennych losowych.

Suma zmiennych to suma wariancji +- suma kowariancji

Jeżeli zmienne X i Y są niezależne to kowariancja jest 0. Tego twierdzenia nie można odwrócić.

Współczynnik korelacji liniowej Pearsona.

Macierz kowariancji (momentów)

Nie rozumiem co tu się dzieje.

Centralne twierdzenie graniczne — jeśli ciąg zmiennych losowych $Y_{n\space n \in N}$ jest zbieżny według rozkładu do zmiennej losowej Y o rozkładzie $N(0,1)$

Twierdzenie Lindberga - Levy'ego i Moivre'a - Laplace'a

Elementy statystyki opisowej
