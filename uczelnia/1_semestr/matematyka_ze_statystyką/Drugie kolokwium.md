# Szereg Maclaurina
**Zadanie za 4 pkt, więc może nie jest to największy priorytet ale dla kujonów może być**

Dajmy na to takie zadanie.

**Obliczyć $\cos \frac{1}{8}$ z dokładnością do $0.00000000001$ posługując się rozwinięciem funkcji $f(x)$ w szeregu Maclaurina.**

Słuchaj mordo, to bardzo proste zadanie! Otóż robimy coś takiego, że:
- Bierzemy se funkcje podaną w zadaniu, tutaj $\cos x$
- Liczymy dla niej kilka pochodnych, tyle, aż wartości zaczną się powtarzać. Rozumisz?! Czyli w naszym przypadku bierzesz tego cosinusa jebanego i go różniczkujesz jakby jutra miało nie być. Czyli 
 $$
\begin{aligned}
f(x) =& \cos(x) \\
f'(x) =& -\sin(x) \\
f''(x) =& -\cos(x) \\
f'''(x) =& \sin(x) \\
f''''(x) =& \cos(x) \\
\end{aligned}
$$
Jak widać na załączonym wyżej obrazku 4 pochodna to ponownie cos, więc dalej nie liczysz. Czaisz to kurwa???
- Obliczamy wartości tych pochodnych w $0$. Dla szerego Maclaurina __zawsze__ w $0$. Czyli tutaj:
 $$
\begin{aligned}
f(0) =& \cos(0) =& 1 \\
f'(0) =& -\sin(0) =& 0 \\
f''(0) =& -\cos(0) =& -1 \\
f'''(0) =& \sin(0) =& 0 \\
f''''(0) =& \cos(0) =& 1 \\
\end{aligned}
$$
- Potem podstawiamy do wzoru na rozwinięcie szeregu:
$$
f(x) = f(0) + \frac{f'(0)}{1!}x + \frac{f''(0)}{2!}x^2 + \frac{f'''(0)}{3!}x^3 + \dots + \frac{f^{(n)}(0)}{n!}x^n + R_n(x)
$$
Jakbyś się zastanawiał co to jest $R_n(x)$ to sie kurwa tyle nie zastanawiaj. Jak już koniecznie musisz to wiedzieć to wiedz, że to jest __jebana__ reszta szerego Macularina, którą tutaj __jebiesz__, bo nie jest nam do niczego potrzeba. Wyjebane w nią miej.

Tam pod $f'(0)$ podstawiasz poprzednio wyliczone wartości
- Jak już to masz to zajebiście, jesteśmy niemal w domu. Teraz wystarczy jeno uprościć.
- Uprościłeś? To tera pa na to:
$$
\cos(\frac{1}{8}) \approx 1 - \frac{(\frac{1}{8})^2}{2} + \frac{(\frac{1}{8})^4}{24} \approx 0.992197667
$$
- Brawo, teraz skończyłeś. Jedyne co ci pozostało to zaokrąglić do podanego w polecenia miejsca po przecinku. Chyba kurwa umiesz zaokrąglać jak jesteś na studiach? Nie będę tego robił. Jak nie umiesz to spierdalaj
# Obliczyć całki
**Zadanie za fhuj dużo punktów, więc lepiej umieć**

Tu jest kwestia zawiła, gdyż mamy różne metody, azaliż pozwolisz, mocium panie, iż wyłożę je teraz wszystkie z należytą staranności i dokładnością.

## Całkowanie przez podstawienie
Prosta piłka jak chuj. Jedyny szkopuł, który tutaj może przeszkadzać to taki, że trzeba umieć liczyć pochodne i dosyć dobrze je widzieć. Generalnie metoda jest taka, że:
- Bierzemy jakąś pojebaną całkę typu
$$
\int \frac{\sqrt[4]{3 + \operatorname{ctg}x}}{\sin ^2x}dx
$$
Widzisz to i myślisz sobie *o kurwa co ja mam zrobić???*
A to nie jest wcale takie trudne, bo metoda jest prosta. Otóż:
- Bierzesz to co wygląda na pojebane i podstawiasz pod $t$. Potem liczysz z tego $t$ pochodną.
W tym przypadku konkretnym wygląda to tak:
$$
\begin{aligned}
t =& 3 + \operatorname{ctg}x \\
dt =& -\frac{1}{\sin^2x}dx \\
-dt =& \frac{1}{\sin^2x}dx
\end{aligned}
$$
No i co nam to w zasadzie __kurwa__ dało? Żeby to wiedzieć, trzeba umieć liczyć pochodne, mieć oczy i *myśleć*! Jak się zastanowisz nad tym, to ta część w mianowniku $dt$, to to samo co mianownik naszej całki! 
- Jeżeli teraz wykonamy podstawienie to:
$$
\int \sqrt[4]{t} \times \operatorname-{dt}
$$
Jak nie widzisz co się stało to zamieniliśmy ten mianownik na $dt$.

- Teraz po prostu to liczymy ze wzoru:
$$
\int \sqrt[4]{t} \cdot -\operatorname{dt} = -\frac{4}{5}\sqrt[4]{t^5}
$$
- Nie można zapomnieć o podstawieniu!
$$
-\frac{4}{5}\sqrt[4]{(3 + \operatorname{ctg}x)^5} + C
$$
I to jest nasz wynik.
## Całkowanie przez części
Bardzo schematyczna metoda. Jak mamy taką całkę, że jej ni chuja nie da się policzyć to:
- bierzemy część całki i oznaczamy ją jako $u$. To różniczkujemy.
- bierzemy drugą część i oznaczamy ją jako $v'$. To całkujemy.
- $u \cdot v'$ musi dawać nam te oryginalną całkę
- podstawiamy do wzoru, który wygląda tak:
$$
u \cdot v - \int u' \cdot v
$$
- Powtarzamy aż do skutku! (można by rzec, że to algorytm rekurencyjny? być może…)
## Całki z pierwiastkami
Esencjonalnie trzeba zawsze sprowadzić do dwóch form:
$$
\begin{align}
\int\sqrt{a^2 - x^2} dx \\
\int\sqrt{x^2 + a} dx\\
\end{align}
$$
Jak już mamy takie  gówno to liczymy ze wzoru.

Jak to tak przekształcić? Pewnie jakimiś wzorami skróconego mnożenia, dodaniem czegoś, odjęciem. Takie szmery bajery.
## Całki wymierne
Tutaj też wchodzą wzory. (nie chce mi sie ich przepisywać xd)
![](../../../media/Pasted%20image%2020260120192400.png)

Trzeba przekształcić wielomian do takiej formy. Robimy to albo licząc deltę, przekształcając w formę kanoniczną albo jakimiś innymi wymyślnymi metodami.

Jak mamy w mianowniku funkcje co się ją da rozłożyć to robimy taki myk, że rozbijamy na dwa ułamki z licznikiem A i B, a potem wyliczamy te liczniki układem równań.

np.
$$
\begin{aligned}
% 1. Uproszczenie całki
\int \frac{5x-2}{2x^2 - 10x + 8} \,dx &= \frac{1}{2} \int \frac{5x-2}{x^2 - 5x + 4} \,dx \\[1em]

% 2. Miejsca zerowe mianownika
x^2 - 5x + 4 &= 0 \implies \Delta = 9, \quad x_1 = 1, \ x_2 = 4 \\
x^2 - 5x + 4 &= (x-1)(x-4) \\[1em]

% 3. Rozkład na ułamki proste
\frac{5x-2}{(x-1)(x-4)} &= \frac{A}{x-1} + \frac{B}{x-4} \quad | \cdot (x-1)(x-4)\\
5x - 2 &= A(x-4) + B(x-1) \\
5x - 2 &= Ax - 4A + Bx - B \\
5x - 2 &= (A+B)x + (-4A-B) \\[1em]

% 4. Układ równań (porównanie współczynników)
&\begin{cases}
A + B = 5 \\
-4A - B = -2
\end{cases} \\
\text{Dodajemy stronami: } \quad -3A &= 3 \implies A = -1 \\
\text{Podstawiamy A: } \quad -1 + B &= 5 \implies B = 6 \\[1em]

% 5. Obliczenie całki
I &= \frac{1}{2} \int \left( \frac{-1}{x-1} + \frac{6}{x-4} \right) \,dx \\
&= \frac{1}{2} \left( -\ln|x-1| + 6\ln|x-4| \right) + C \\
&= -\frac{1}{2}\ln|x-1| + 3\ln|x-4| + C
\end{aligned}
$$
Takie coś xdd

# Obliczyć całki oznaczone
Całki oznaczone różnią sie od nieoznaczonych tym, że jak już się już obliczy to trzeba jeszcze podstawić górna i dolną granicę i odjąć drugie od pierwszego.
$$
\begin{aligned}
I &= \int_{0}^{4} \frac{e^{\sqrt{x}}}{\sqrt{x}} \,dx \\[1em]

t &= \sqrt{x} \implies dt = \frac{1}{2\sqrt{x}} \,dx \\
2\,dt &= \frac{1}{\sqrt{x}} \,dx \\[1em]

x &= 0 \implies t = \sqrt{0} = 0 \\
x &= 4 \implies t = \sqrt{4} = 2 \\[1em]

I &= \int_{0}^{2} e^t \cdot 2 \,dt \\
&= 2 \int_{0}^{2} e^t \,dt \\
&= 2 \left[ e^t \right]_{0}^{2} \\
&= 2 (e^2 - e^0) \\
&= 2(e^2 - 1)
\end{aligned}
$$
**Uwaga**, jeśli liczysz przez podstawienie to miej na baczności, że podstawiamy granice dla całego wyrażenia!!

# Obliczyć pole ograniczone wykresem
- Przyrównać obie funkcje do siebie
- policzyć miejsca zerowe tego co wyszło – to sa granice całki
- liczymy p i q paraboli
- pod całką odejmujemy funkcje wyżej od tej niżej
- obliczamy
- wynik 
- profit
