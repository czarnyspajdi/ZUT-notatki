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
