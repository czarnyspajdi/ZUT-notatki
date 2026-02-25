# Źródła
[Bardzo fajne źródło](/https://www.matemaks.pl/szeregi-liczbowe.html)
# Wstęp
## Suma szeregu
Granice szeregu nazywamy jego sumą.
Czyli lim Xn = (sigma)^(nieskończoność) n=1 Xn
Dla ciągu Xn określamy ciąg Sn wzorem Sn = (sigma)^n i=1 Xi
wtedy
S1 = X1
S2 = X1 + X2
S3 = X1 + X2 + X3
itd.
## Szereg harmoniczny
Tak wygląda szereg harmoniczny (to szereg ciągu 1/n\[Czyli innymi słowy: mamy ciąg 1/n, dodajemy wszystkie jego elementy(to jest szereg), wtedy jego granica(suma szeregu) wynosi nieskończoność(bo wszystkie jego wyrazy można uprościć do 1 + 1/2 + 1/2 + 1/2 ... + 1/2, jeśli zgrupujemy kolejne wyrazy w nawiasy, które zawierają w sobie 2^n elementów) więc nigdy nie przestaje on rosnąć.)])
![Pasted image 20251011092804](/media/Pasted%20image%2020251011092804.png)


Dowód zbieżności  (a raczej rozbieżności) szeregu harmonicznego.
![Pasted image 20251011092828](/media/Pasted%20image%2020251011092828.png)

# Obliczanie zbieżności szeregów
Szereg jest zbieżny, gdy Sn sum częściowych jest zbieżny. 
Zbieżność oznacza dążenie do konkretnej liczby.
Rozbieżność oznaczy dążenie nieokreślonej wartości (nieskończoność, minus nieskończoność\[to jest - szereg rośnie, rośnie i rośnie, nie wiemy kiedy przestanie rosnąść])

Jeżeli szereg jest zbieżny, to granica ciągu jest równa 0.
## Kryterium Cauche'ego (pierwiastkowe)
Jeżeli granica z sqrt(an, n) < 1, to szereg jest zbieżny
Jeżeli granica z sqrt(an, n) > 1, to szereg jest rozbieżny
Jeżeli granica z sqrt(an, n) = 1, to kryterium nie rozstrzyga zbieżności szeregu

Dodatkowo, jeśli od pewnego momentu >= 1, to jest to szereg rozbieżny.

Kryterium Cauchy'ego często wykorzystuje się podczas badania zbieżności szeregów, we wzorach których występują potęgi n-tego stopnia.

Czyli intuicyjnie:
- Gdy granica pierwiastka stopnia n z każdego kolejnego elementu ciągu jest mniejsza niż 1, to te pierwiastki muszą sumować się do 1, bo będziemy sumować coraz to mniejsze ułamki (to tak jakbyśmy w nieskończoność zamalowywali coraz mniejszy element kwadratu- gdybyśmy w nieskończoność zamalowywali coraz to mniejsze części, to w końcu zamalujemy go całego)
- Gdy ta  granica jest większa od 1, to dodajemy pierwiastki coraz to większych liczby, więc ucieka nam to w nieskończoność.
- Gdy ta granica jest równa 1, to nic nam to nie mówi

## Kryterium d'Alemberta (ułamkowe)
Dla ciągu o wyrazach (an + 1) / an:
- Jeżeli granica jest mniejsza niż 1, to szereg jest zbieżny
- Jeżeli granica jest większa od 1, to szereg jest rozbieżny
- Jeżeli jest równa 1, to nic nam to nie mówi

Dodatkowo jeśli od pewnego momentu granica jest >= 1, to szereg jest rozbieżny.

Na ludzki:
Gdy mamy taki szereg, że każdy kolejny element ciągu to element ciągu zwiększony o 1 i podzielony przez ten element, to
- przy granicy mniejszej od 1 będziemy dodawali ułamki, więc zbiegamy do 1
- przy granicy większej od 1 będziemy uciekali do nieskończoności
- przy granicy równej 1 nic nam to nie mówi

## Kryterium porównawcze
Porównujemy szereg, którego zbieżność znamy z innym, który badamy.

Dla dwóch dodatnich szeregów:
A i B

Jeżeli dla prawie wszystkich n zachodzi a, <= bn to:
- ze zbieżności szeregu B wynika zbieżność szeregu A
- z rozbnieśności szeregu A wynika rozbieżność szeregu B

Czyli tłumacząc to na język bardziej ludzki. Gdy kolejne elementy ciągu są mniejsze, niż elementy drugiego ciągu, to:
- ze zbieżności większego wynika zbieżność mniejszego
- z rozbnieżności mniejszego wynika rozbieżność większego

Jeśli mniejszy ucieka w nieskończoność, to większy tym bardziej.
Jeśli większy zbiega do konkretnej wartości, to mniejszy tym bardziej.

To opiera się na porównywaniu do szeregu harmonicznego.
# Podsumowanie
Wszystkie te kryteria działają podobnie. Cauche'ego i d'Alemberta mówi nam, że gdy kolejne elementy ciągu są mniejsze/większego to szereg będzie zbieżny/rozbieżny. Pierwszy w przypadku pierwiastków, drugi w przypadku ułamków. Kryterium porównawcze mówi nam to samo, ale w przypadku, gdy mamy 2 różne szeregi.