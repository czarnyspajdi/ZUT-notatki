# układ równań

A = matrix(c(-9, 15, -14, -1, 13, 5, 18, 6, 8, 12, 10, -4, -1, 5, 8, 12), 4, 4)
B = c(4, 298, 294, 120)
solve(A, B)

solve(A)
solve(A)[1, 4]

# wektory

## Skonstruować wektor w trzecich potęg wielokrotności liczby 7 od 21 do 29903
## następnie zliczyć, ile wśród elementów tego wektora jest liczb, których dwie ostatnie cyfry to
## 23.
w = seq(21, 29903, 7)^3
summary.factor(w %% 100 == 23)


## Skonstruować wektor w kwadratów liczb od 1 do 100 a następnie zliczyć, które
## cyfry oraz jak często występują na pozycji jedności w wyznaczonych kwadratach (użyć operatora modulo, funkcji summary oraz typu factor). Ile wśród kwadratów liczb od 1 do 100 jest
## podzielnych przez 2, przez 3 oraz przez 2 i 3?

w = (1:100)^2
summary.factor(w %% 2 == 0)
summary.factor(w %% 3 == 0)
summary.factor(w %% 3 == 0 & w %% 2 == 0)

# dwumianowy i geom | lista 2

# zad 1

# P(X = 2)
dbinom(2, 4, 1/3)
# P(X < 2)
pbinom(1, 4, 1/3)
# P(X > 2)
pbinom(2, 4, 1/3, F)


# zad 2
prob = 0.02
dgeom(3, prob)

pgeom(2, prob)

# zad 3
size = 100
prob = 0.01
# P(X = 2)
dbinom(2, size, prob)
dpois(2, size * prob)

# P(2 < X < 6)
sum(dbinom(2:6, size, prob))

pbinom(3, size, prob, F)

# zad 4
dbinom(2, 4, 1/7)

dbinom(3, 5, 1/2) > dbinom(2, 3, 1/2)

# kwantyle
qnorm(0.97)
qchisq(0.975, 9)
qt(0.95, 9)
qf(0.995, 10, 23)


# zad 2
# d)
# |x - 2| < 3
# x - 2 < 3 || x - 2 > -3
# x < 5 || x > -1
pnorm(5, 1.5, 2) - pnorm(-1, 1.5, 2)


# e)
# |x| > 0.5
# x > 0.5 || x < -0.5
pnorm(-0.5, 1.5 ,2) + pnorm(0.5, 1.5, 2, F)

# f)
# -1 < 2x - 1 < 1
# 0 < 2x < 2
# 0 < x < 1
pnorm(1, 1.5, 2) - pnorm(0, 1.5, 2)

# g)
# 3x - 1 > 2 || 3x -1 < -2
# 3x > 3 || 3x < -1
# x > 1 || 3 < -1/3
pnorm(-1/3, 1.5, 2) + pnorm(1, 1.5, 2, F)

# zad 3
# 5x - 1 > 2.5 || 5x -1 < -2.5
# 5x > 3.5 || 5x < -1.5
pnorm(-1.5/5, -4, 3.5) + pnorm(3.5/5, -4, 3.5, F)

# 4x - 2 <= 5.5 || 4x -2 >= -5.5
# -5.5 < 4x - 2 < 5.5
# -3.5 < 4x < 7.5
pnorm(7.5/4, -4, 3.5) - pnorm(-3.5/4, -4, 3.5)

# zad 4
# P(X < 900)
round(pnorm(900, 1000, 50) * 4000)
qnorm(0.13, 1000, 50, F)

# zad 5
round(pnorm(7.1, 6.8, 0.3) * 30)
qnorm(0.15, 6.8, 0.3)

# zad 6
# 22:05 < X < 22:10
# 22 * 5/60 < X < 22 * 10/60
pnorm(22 * 1/6 * 60, 15, 13) - pnorm(22 * 5/60 * 60, 15, 13)

pnorm(22, 15, 13, F)

# standaryzacja rozkładu normalnego
# zad 1
# P(X > 5) = 70/200
sigma = 1
m = 5 - sigma * qnorm(70/200, lower.tail = FALSE)
round(pnorm(6, m, sigma) - pnorm(3, m, sigma), 4)

# P(X < 6) = 0.8
sigma = sqrt(4)
m = 6 - sigma * qnorm(0.8)
round(pnorm(6, m, sigma) - pnorm(3, m, sigma) ,4)

# zad 2
m = 5.2
U = qnorm(0.121)
sigma = (3 - m)/U
qnorm(0.8, m, sigma)

# zad 3
m = -5
X = -2
U = qnorm(0.95)
sigma = (X - m)/U
pnorm(0, m, sigma, F)

# zad 4
m = 0.46
X = 0.5
U = qnorm(0.6)
sigma = (X - m)/U
pnorm(0.7, m, sigma, F)

# zad 1
A = matrix(c(1, 1, qnorm(3/10), qnorm(3/4)), 2, 2)
B = c(5281.21, 9090.9)
wynik = solve(A, B)
m = wynik[1]
sigma = wynik[2]

pnorm(7800, m, sigma, F) * 100
qnorm(0.15, m, sigma)


# zad 3
m = 165.5
# 155 < X < 176
U = qnorm((1 - 0.93)/2)
sigma = (155 - m)/U
round(pnorm(170, m, sigma, F) * 100)

# zad 4
A = matrix(c(1, 1, qnorm(1/12, lower.tail = FALSE), qnorm(2/12)), 2, 2)
B = c(0.9, 0.5)
wynik = solve(A, B)
m = wynik[1]
sigma = wynik[2]
qnorm(0.1, m, sigma, F)

A = matrix(c(1, 1, qnorm(11/12), qnorm(2/12)), 2, 2)
B = c(0.9, 0.5)
wynik = solve(A, B)
m = wynik[1]
sigma = wynik[2]

qnorm(0.1, m, sig, F)

# zadanie 2 lista 6
n = 2000
p = 0.002
q = 1 - p

sum(dbinom(6:12, n, p))
if (n >= 50 & p < 10) {
  print("Rozkład poissona")
  sum(dpois(6:12, n * p))
} else {
  print("Nie można użyć rozkładu poissona")
}



