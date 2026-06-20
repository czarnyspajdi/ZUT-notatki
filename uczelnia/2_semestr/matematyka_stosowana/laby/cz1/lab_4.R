# zadanie 1

# a)
# P(x > 5) = 70 / 200
x_5 = 70 / 200
# P(x <= 5) = 1 - x_5
x_5_F = 1 - x_5
sigma = 1
# (5 - m) / sig = qnorm(1 - 70/200)
m = 5 - sigma * qnorm(x_5_F)

round(pnorm(6, m, sigma) - pnorm(3, m, sigma), 4) # 0.8638

# b)
# P(x < 6) = 0.8
x_6 = 0.8
wariancja = 4
sigma = sqrt(wariancja) # 2
# (6 - m) / sigma = qnorm(0.8)
m = 6 - qnorm(0.8) * sigma
round(pnorm(6, m, sigma) - pnorm(3, m , sigma), 4) # 0.5449

# zadanie 2
m = 5.2 # w procentach

# P(x < 3) = 12.1%
P_x = 0.121
# (3 - m) / sigma = qnorm(P_x)
sigma = (3 - m)/qnorm(P_x)
print(sigma) # 1.880338

qnorm(0.8, m, sigma) # 6.782532%

# zadanie 3
m = -5
# P( X < -2) = 0.95
sig = (-2 - m)/qnorm(0.95)
sig # 4.255698
# P(X > 0)
pnorm(0, m, sig, F) # 0.003058688

# zadanie 4
# aby zdać: ponad 50%
# pierwszy termin: średnio: 46%, zdawalność: 40%

# a)
# P(X > 0.7) = ?
a = 0.7
m = 0.46
sigma = (0.5 - m)/qnorm(0.6)
pnorm(0.7, m, sigma, F)
# b)
qnorm(0.1, m, sigma, F)


# zadanie 5
sigma = 0.12
# P(x > 0.8) = 3/12
P_x = 3/12
# (0.8 - m) / sigma = qnorm(3/12)
m = 0.8 - qnorm(1 - P_x) * sigma
qnorm(0.1, m, sigma, F) # 0.8728474

# zadanie 6
m = 86.5
P_x = 0.3472
a = 82.5

sigma = (a - m)/qnorm((1 - P_x)/2)
round(pnorm(95, m, sigma, F) * 400) # 68




