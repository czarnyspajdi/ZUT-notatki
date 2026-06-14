# będzie zadanie na kolokwium na rozkład geometryczny i Poissona

# zadanie 1
# rozkład dwumianowy

# a)
dbinom(2, 4, 1/3) # 0.2962963

# b)
pbinom(1, 4, 1/3) # 0.5925926

# c)
pbinom(2, 4, 1/3, F) # 0.1111111

# zadanie 2

# a)
dgeom(3, 0.02) # 0.01882384

# b)
pgeom(2, 0.02) # 0.058808

# zadanie 3

# a)
dbinom(2, 100, 0.01) # 0.1848648
dpois(2, 100 * 0.01) # 0.1839397


# b)
pbinom(6, 100, 0.01) - pbinom(1, 100, 0.01) # 0.2641669
sum(dbinom(2:6, 100, 0.01)) # 0.2641669
# obie metody są poprawne!

sum(dpois(2:6, 100 * 0.01)) # 0.2641579

# c)
pbinom(3, 100, 0.01, F) # 0.01837404
ppois(3, 100 * 0.01, F) # 0.01898816

# zadanie 4
# a)
dbinom(2, 4, 1/7) # 0.08996252

# b
dbinom(3, 5, 1/2) # 0.3125
dbinom(2, 3, 1/2) # 0.375

# zadanie 5
pbinom(3, 525, 0.004, F) # 0.1610156

#zad6
dbinom(3,10,1/2)
#b

sum(dbinom(4:7,10,1/2))

# zadanie 7
# a)
dgeom(7, 1/6) # 0.04651361

# b)
pgeom(4, 1/6, F) # 0.08037551

# zadanie 8
pbinom(3, 400, 0.005, F) # 0.1424233

# zadanie 9


# zadanie 10
# a)
dgeom(4,4/36) # 0.06936612

# b)
pgeom(3, 4/36, F) # 0.6242951