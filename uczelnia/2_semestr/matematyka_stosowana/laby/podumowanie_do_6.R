
# === Lista 1 ===


# rozwiązywanie układu równań

# zadanie 3

macierz_ukladu = matrix(c(1, 2, 5, -2, 1, 2, 5, -3, -1, 0, 2, 1, -2, 3, 5, 2), 4, 4) # wypisujemy liczby kolumnami w pierwszy argumencie, w drugim ile wierszy, w trzecim ile kolumn
macierz_rozwiazan = c(-7, 21, 40, 2) # wektor rozwiązań
solve(macierz_ukladu, macierz_rozwiazan) # solve(A, B) rozwiązuje układ równań

solve(macierz_ukladu)[2, 3] # podaje wartość elementu w drugim wierszu, w trzeciej kolumnie macierzy odwrotnej do macierzy układu

# zadanie 7

macierz_ukladu = matrix(c(-9, 15, -14, -1, 13, 5, 18, 6, 8, 12, 10, -4, -1, 5, 8, 12), 4, 4)
macierz_rozwiazan = c(4, 298, 294, 120)
solve(macierz_ukladu, macierz_rozwiazan) # rozwiązujemy układ


# zadanie 4

# wektory wielokrotności i potęg
w = (1:100)^2 # wektor zawierający kwadraty liczb od 1 do 100
summary.factor(w%%10) # wyświetla ile liczb występuje na pozycji dziesiątek
summary.factor(w%%2 == 0) # zlicza ile liczb jest podzielnych przez 2
summary.factor(w%%3 == 0) # zlicza ile liczb jest podzielnych przez 3
summary.factor(w%%3 == 0 & w%%2 == 0) # zlicza ile jest podzielnych przez oba

# zadanie 5
w = seq(21, 29903, 7)^3 # wektor wielokrotności liczby 7 od 21 do 29903
summary.factor(w %% 100 == 23) # ile liczb w tym wektorze kończy się na 2 ostatnie cyfry 23

# === Lista 2 ===

# typ skokowy

# zadanie 1
dbinom(2, 4, 1/3) # prawdopodobieństwo, że nauczyciel wybierze 2 osoby z dostępnych 4 jeśli prawdopodobieństwo wybrania jednej wynosi 1/3. używamy dbinom jeśli prawdopodobieństwo ma być równe X (pierwszemu argumentowi)
pbinom(1, 4, 1/3) # prawdopodobieństo wybrania mniej niz 2 osób. pbinom jeśli X <= wartość (tu mniejszy równy 1)
pbinom(2, 4, 1/3, F) # prawdopodobieństwo wybrania co najmniej 3 osób (czyli więcej niż 2 osób). pbinom z F na końcu

# binom jeśli liczba sukcesów

# zadanie 2

dgeom(3, 0.02)
pgeom(2, 0.02)

# geom jeśli liczba porażek do pierwszego sukcesu

# zadanie 3

dbinom(2, 100, 0.01)
dpois(2, 100 * 0.01)

# można zrobić dwoma funkcjami ale nie wiem czemu

pbinom(6, 100, 0.01) - pbinom(1, 100, 0.01) # odejmujemy szansę na co najmniej 6 elementów od szansy na co najmniej 1 element
sum(dbinom(2:6, 100, 0.01)) # sumujemy prawdopodobieństwo | lepsza metoda

pbinom(3, 100, 0.01, F) # co najmniej 4 elementy
ppois(3, 100 * 0.01, F)


# === Lista 3 ===
# typ ciągły

# zadanie 1
qnorm(0.97, 0, 1) # rozkład normalny od 0 do 1 (to wartości domyślne tych argumentów więc bez też zadziała)
qchisq(0.975, 9)
qt(0.95, 9)
qf(0.995, 10, 23)


# zadanie 2
pnorm(2.5, 1.5, 2)
pnorm(-0.5, 1.5, 2, F)

round(pnorm(2, 1.5, 2) - pnorm(0.5, 1.5, 2), 4)

round(pnorm(5, 1.5, 2) - pnorm(-1, 1.5, 2),4)

# zadanie 3
#b)
round(pnorm(0.7, -4, 3.5, F) + pnorm(-0.3, -4, 3.5),4)
#d)
pnorm(7.5/4, -4, 3.5) - pnorm(-3.5/4, -4, 3.5)

# zadanie 4
round(pnorm(900, 1000, 50) * 4000)
qnorm(0.13, 1000, 50, F)

# === Lista 4 ===
# zadanie 1
#a)
sigma = 1
# P(3 < X < 6)
U = qnorm(1 - 70/200)
m = 5 - U * sigma 

round(pnorm(6, m, sigma) - pnorm(3, m, sigma), 4)

# b)
sigma = sqrt(4)
U = qnorm(0.85)

m = 6 - U * sigma 
round(pnorm(6, m, sigma), 4)


# zadanie 2
m = 5.2
# P(X < 3) = 12.1
X = 3
U = 0.121
sigma = (X - m)/qnorm(U)
qnorm(0.8, m, sigma)

# zadanie 3
m = -5
# P(X < 2) = 0.95
U = qnorm(0.95)
sig = (-2 - m) / U
pnorm(0, m, sig, F)

# zadanie 4
X = 0.7
U = qnorm(1 - 0.4)
m = 0.46

sigma = (0.5 - m) / U
pnorm(X, m, sigma, F)
qnorm(0.1, m, sigma, F)

# zadanie 5
sigma = 0.12
# P(X > 0.8) = 3/12
U = qnorm(3/12, lower.tail = FALSE)
X = 0.8
m = X - U * sigma
qnorm(0.1, m, sigma, F)

# zadanie 6
m = 86.5
X = 90.5
U = qnorm((0.3472 /2) + 0.5)
# P(82.5 < X < 90.5) = 0.3472
sigma = (X - m) / U
round(pnorm(95, m, sigma, F) * 400)

# === Lista 5 ===

# zadanie 1
# qnorm(3/10) = 5281.21
# qnorm(3/4) = 9090.90

A = matrix(c(1, 1, qnorm(3/10), qnorm(3/4)), 2, 2)
B = c(5281.21, 9090.9)
wynik = solve(A, B)
m = wynik[1]
sigma = wynik[2]

#a)
# P(X > 7800)
pnorm(7800, m, sigma, F) * 100

# b)
round(qnorm(0.15, m, sigma), 2)

# zadanie 2
# qnorm(0.2) < 2 
A = matrix(c(1, 1, qnorm(0.2, lower.tail = FALSE), qnorm(0.44)), 2, 2)
B = c(120, 90)
wynik = solve(A, B)
m = wynik[1]
sigma = wynik[2]

# a)
pnorm(45, m, sigma)

# b)
qnorm(0.13, m, sigma, F)

# zadanie 3
m = 165.5
# 155 < qnorm(0.93) < 176
U = qnorm(0.93 / 2 + 0.5)
X = 176
sigma = (X - m) / U

round(pnorm(170, m, sigma, F) * 500)

# zadanie 4
# qnorm(0.9, lower.tail = False) = 1/12
# qnorm(0.5) = 2/12
A = matrix(c(1, 1, qnorm(1/12, lower.tail = FALSE), qnorm(2/12)), 2, 2)
B = c(90, 50)
wynik = solve(A, B)
m = wynik[1]
sigma = wynik[2]

qnorm(0.1, m, sigma, F)

# zadanie 5
m = 4001.5
# 3503 < P(X) < 4500
X = 3503
U = qnorm((1 - 0.15) / 2)
sigma = (X - m) / U

qnorm(0.25, m, sigma, F)


# zadanie 6
# qnorm(2/524) = 17
# qnorm(7/524, F) = 70
A = matrix(c(1, 1, qnorm(2/524), qnorm(7/524, lower.tail = FALSE)), 2, 2)
B = c(17, 70)
wynik = solve(A, B)
m = wynik[1]
sigma = wynik[2]

pnorm(55, m, sigma) - pnorm(45, m, sigma)

# === Lista 6 ===
n = 2000
p = 0.002
q = 1 - p

sum(dbinom(6:12, n, p))
if (n >= 50 & n * p <= 10) {
  sum(dpois(6:12, n * p))
}

p = q
q = 0.002

sum(dbinom(1992:2000, n, p))
pnorm(1992, n * p, sqrt(n * p * q), F)

 
