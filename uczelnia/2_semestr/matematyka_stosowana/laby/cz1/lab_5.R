# Zadanie 1
A = matrix(c(1, 1, qnorm(0.3), qnorm(0.75)), 2, 2)
B = c(5281.21, 9090.9)
wynik = solve(A, B)
m = wynik[1]
sigma = wynik[2]
print(m)
print(sigma)

# a)
# P(x > 7800)
pnorm(7800, m, sigma, F) * 100 # 39.42534

# b)
round(qnorm(15/100, m, sigma),2) # 3654.13

# zadanie 2
A = matrix(c(1, 1, qnorm(0.8), qnorm(0.44)), 2, 2)
B = c(120, 90)
wynik = solve(A, B)

m = wynik[1]
sigma = wynik[2]

# a)
# P(X < 45)
pnorm(45, m, sigma) # 0.05051767

# b)
qnorm(0.13, m, sigma, F) # 128.6069

# zadanie 3
m = 165.5
sig = (155 - m)/qnorm((1 - 0.93)/2)
round(pnorm(170, m, sig, F) * 500)

# zadanie 4
A = matrix(c(1, 1, qnorm(11/12), qnorm(2/12)), 2, 2)
B = c(0.9, 0.5)
wynik = solve(A, B)
m = wynik[1]
sigma = wynik[2]

qnorm(0.1, m, sig, F)

# zadanie 5
m = 4001.50
sig = (3503 - m)/qnorm((1 - 0.15)/2)
qnorm(0.25, m, sig, F)

# zadanie 6
# 45 < X < 55

A = matrix(c(1, 1, qnorm(2/524), qnorm(517/524)), 2, 2)
B = c(17, 70)
wynik = solve(A,B)
m = wynik[1]
sig = wynik[2]

pnorm(55, m, sig) - pnorm(45, m, sig)
