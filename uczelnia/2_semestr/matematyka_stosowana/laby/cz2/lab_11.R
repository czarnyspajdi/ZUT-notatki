# zadanie 1

# zmienna mierzalna
plony = c(2.6, 2.4, 2, 1.8, 2.2, 1.5, 1.5, 1.4, 1.2, 1.5, 1.2, 1.5, 0.8, 1)
# zmienna grupująca
kombinacje = c(rep('1', 5), rep('2', 4), rep('3', 5))

## Normalność rozkładów

### (wariant skrócony)
by(plony, kombinacje, shapiro.test)
# kombinacja 1: W = 0.98676, p-value = 0.9672
# kombinacja 2: W = 0.82743, p-value = 0.1612
# kombinacja 3: W = 0.90345, p-value = 0.4292

# Brak podstaw do odrzucenia hipotez zerowych

## Jednorodność wariancji
# h0: sigma^2 = (sigma.2)^2 = (sigma.3)^2
# h1: ~h0
bartlett.test(plony ~ kombinacje)
# Bartlett's K-squared = 1.8396, df = 2, p-value= 0.3986

# alpha < p-value – Brak podstaw do odrzucenia h0

## Test anova
# h0: m.1 = m.2 = m.3 (brak wpływu)
# h1: ~h0 (istotny wpływ)

anova(aov(plony ~ kombinacje))

# Response: plony
# Df Sum Sq Mean Sq F value    Pr(>F)    
# kombinacje  2 2.7571 1.37857  18.053 0.0003356 ***
#  Residuals  11 0.8400 0.07636                      

# F: 18.053 p-value: 0.0003356

# Odrzucamy h0, przyjmujemy h1, nawóz ma istotny wpływ

# Wniosek: na poziomie istotności 0.05 odrzucamy h0 i przyjmujemy h1, zatem nawożenie istotnie wpływa na plony rzepaku jarego.


# Zadanie 2

# Jedna próba

## Test normalności rozkładu

# wariant skrócony

shapiro.test(Ankieta.M$Waga)
# W = 0.94653, p-value = 0.009113

# Odrzucamy h0

# Test nieparametryczny Wilcoxona
# h0: mediana = 70
# h1: mediana > 70
wilcox.test(Ankieta.M$Waga, mu = 70, alternative = 'g')
# V = 1129.5, p-value = 0.008091

# Wniosek: na poziomie istotności 0.05 odrzucamy h0 i przyjmujemy h1. Zatem mediana wagi populacji mężczyzn studiujących na I roku WI ZUT w Szczecinie jest istotnie większa od 70kg.


# Zadanie 3

# Dwie niezależne próby

utargi = c(7.6, 12.0, 7.3, 11.3, 7.0, 10.8, 6.5, 8.1, 3.2, 8.7, 8.8, 11.7, 12.7, 18.5, 3.3, 6.7, 8.6, 6.9, 3.8, 3.7) # zmienna mierzalna
miasta = c(rep('A', 13), rep('B', 7)) # zmienna grupująca

## Normalność rozkładu
# wariant skrócony
by(utargi, miasta, shapiro.test)
# Miasto A:  W = 0.94565, p-value = 0.5341
# Brak podstaw do odrzucenia h0

# Miasto B:  W = 0.76886, p-value = 0.01989
# Odrzucamy h0

# Wniosek: odrzucamy hipotezę, że rozkład miesięcznego utargu w mieście B jest zgodny z rozkładem normalnym.

## Test nieparametryczny wilcoxona
# h0: mediana.A = mediana.B
# h1: mediana.A > mediana.B

wilcox.test(utargi ~ miasta, alternative = 'g')
# W = 65, p-value = 0.0674
# brak podstaw do odrzucenia h0

# Wniosek: Na poziomie istotności 0.05 nie ma podstaw by odrzucić hipotezę h0. Mediany utargów w mieście A i B nie różnią się istotnie.

# Zadanie 4

# Dwie zależne próby
x1 = c(85, 122, 162, 206, 121, 250, 200, 156)
x2 = c(87, 82, 158, 96, 131, 121, 194, 130)

## Normalność rozkładu różnicy zmiennych
# wariant skrócony
shapiro.test(x1 - x2)
# W = 0.81838, p-value = 0.04487

# Wniosek: odrzucamy h0

## Test nieparametryczny Wilcoxona: próby zależne
# h0: mediana1 - mediana2 = 0
# h1: mediana1 - mediana2 > 0

wilcox.test(x1, x2, paired = T, alternative = 'g')
# V = 31, p-value = 0.03906

# Odrzucamy h0 i przyjmujemy h1

# Wniosek: na poziomie istotności 0.05 odrzucamy h0 i przyjmujemy h1, zatem trening istotnie wpływa na skrócenie czasu potrzebnego myszom na wyjście z labiryntu.


# Zadanie 5
frewkencja = c(32.5, 40.8, 41.7, 41.2, 37.9, 38.3, 42, 39.8, 43.1, 42.6, 38.9, 43.1, 40.4, 41.8, 42, 39, 43.7, 40, 39.7, 43, 43.1, 43.9, 44.2, 45.2, 44.6, 42.5, 43.4, 44.8, 42.8, 43.1, 44.8, 45)
miasta = c(rep('Wroclaw', 10), rep('Warszawa', 11), rep('Krakow', 11))
# alhpa = 0.05
# 3 próby

## Jednorodność wariancji
# h0: sigma^2 = (sigma.2)^2 = (sigma.3)^2
# h1: ~h0
bartlett.test(frewkencja ~ miasta)
# Bartlett's K-squared = 11.774, df = 2, p-value = 0.002775
# aplha > p-value
# odrzucamy h0, przyjmujemy h1

# h0: mediana.1 = mediana.2 = mediana.3
# h1: ~h0
kruskal.test(frewkencja ~ miasta)

# Kruskal-Wallis chi-squared = 16.791, df = 2, p-value = 0.0002259
# alpha > p-value
# odrzucamy h0 i przyjmujemy h1

# Wniosek: na poziomie istotności 0.05 odrzucamy h0 i przyjmujemy h1, zatem frekwencja w wyborach prezydenckich dla wszystkich tych miast nie jest taka sama.


# Zadanie 8
# 3 próby

# alpha = 0.01

## Test normalności
# wariant skrócony

by(Ankieta$L.godzin, Ankieta$M.zamieszkania, shapiro.test)
# akademik: W = 0.96227, p-value = 0.5107
# mieszkanie z rodziną: W = 0.98145, p-value = 0.8405
# stancja lub inne: W = 0.95429, p-value = 0.5278

# W każdej próbce brak podstaw do odrzucenia h0

## Test jednorodności wariancji
# h0: sigma.0^2 = (sigma.1)^2 = (sigma.2)^2
# h1: ~h0

bartlett.test(Ankieta$L.godzin ~ Ankieta$M.zamieszkania)
# Bartlett's K-squared = 0.47545, df = 2, p-value = 0.7884

# alpha < p-value
# brak podstaw do odrzucenia h0, zatem wariancje są jednorodne


# h0: m0 = m1 = m2 (brak wpływu)
# h1: ~h0 (istotny wpływ)

anova(aov(Ankieta$L.godzin ~ Ankieta$M.zamieszkania))
# F - 0.5896 p-value 0.5573
# alpha < 0.5573
# brak podstaw do odrzucenia h0

# Wniosek: Na poziomie istotności 0.01 nie ma podstaw do odrzucenia h0, zatem liczba godzin spędzonych przed komputerem w ciągu doby w popuplacji studentów pierwszego roku WI ZUT w Szczecinie w tym roku akademickim nie zależy od miejsca zamieszkania.
