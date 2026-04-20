# zadanie 1 | zmienne ciągłe
n = 130
m = 7
sig = 1/2

# P(x1 + x2 + ... + xn > 900)

pnorm(900, n * m, sig * sqrt(n), F) # 0.9602947

# zadanie 2 na kolokwium | zmienne skokowe
n = 2000
p = 0.002
q = 1 - p

# a)
# P(6 <= Sn <= 12)
# rozkład dwumianowy
sum(dbinom(6:12, n, p)) # 0.2144444

# rozkład poissona
sum(dpois(6:12, n * p)) # 0.2145959

# b)
# P(Sn >= 1992)
n = 2000
q = 0.002
p = 1 - q

# rozkład dwumianowy
sum(dbinom(1992:2000, n, p)) # 0.9787556

# CTG P(Sn >= 1992) = P(Sn >= 1991.5)
pnorm(1991.5, n * p, sqrt(n * p * q), F) # 0.9878469

# zadanie 3 | zmienne ciągłe
n = 500 / 2
m = 1.99
sig = 0.05

# P(x1 + x2 ... + xn < 500)
pnorm(500, n * m, sig * sqrt(n)) # 0.9992173

# zadanie 4
n = 1000 # ok
p = 0.525 # nie ok
q = 1 - p

# P(450 < Sn < 520)
# P(451 <= Sn <= 519)

sum(dbinom(451:519, n, p)) # 0.3636469
# nie można użyć poissona
pnorm(519.5, n * m, sqrt(n * p * q)) - pnorm(450.5, n * m, sqrt(n * p * q))

# zadanie 5
n = 1200
p = 0.08
q = 1 - p

# P(0.07 < Sn < 0.11)
sum(dbinom(0.08:0.10, n, p))
pnorm(0.10, n * p, sqrt(n * p * q)) - pnorm(0.08, n * p, sqrt(n * p * q)) # 2.053723e-26

# zadanie 6
n = 5000
p = 0.01
q = 1 - p

z = 0.015 * n

# n * p nie jest <= 10, więc nie można użyć poissona
# P(x1 + ... + xn < z)
sum(dbinom(1:z, n, p)) # 0.9996532
pnorm(z, n * p, sqrt(n * p * q)) # 0.9998098
# poprawka ctg
pnorm(z - 0.5, n * p, sqrt(n * p * q)) # 0.9997514


# zadania na kolokwium
# 1. układ równań | lab1
# 2. wektor wielokrotności i do potęgi i zliczyć ile elementów jest podzielnych przez jakieś wartości | lab1
# 3. rozkład z listy nr 2 geometryczny albo dwumianowy
# 4. rozkład normalny i prawdopodobieństwo z wartością bezwzględną | lab 3
# 5. kwantyle | lab 3
# 6. zadanie nr 2 tego co dzisiaj
# 7. standaryzacja rozkładu normalnego, ale 1 niewiadoma (m/sig nieznane) | lab 4 i 5
# 8. standaryzacja rozkładu normalnego, dwie niewiadome | lab 5

