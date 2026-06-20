# zadanie 1

# Próby niezależne

# a)

# założenie 1: normalność rozkładów

# h0 – rozkład średnich ocen w populacji studentek jest normalny
# h1 – ~h0

# h0' – rozkład średnich ocen w populacji studentów jest normalny
# h1' – ~h0'

by(Ankieta$Średnia, Ankieta$Płeć, shapiro.test)

# dla kobiet: W = 0.97625, p-value = 0.942
# dla mężczyzn: W = 0.97148, p-value = 0.1578
# aplha = 0.01

# w obu przypadka alpha < p-value
# brak podstaw do odrzucenia h0 i h0'

# b)

# h0 – jednorodność wariancji sigma.k^2 = sigma.m^2
# h1 – ~h0

var.test(Ankieta$Średnia ~ Ankieta$Płeć)
# F = 0.40623, num df = 9, denom df = 61, p-value = 0.1459
# alpha = 0.01

# Wniosek: brak podstaw do odrzucenia h0
# będziemy stosować test bez poprawki welcha

# c)

# h0 – m.kobiet = m.mężczyzn
# h1 – m.kobiet > m.mężczyzn


t.test(Ankieta$Średnia ~ Ankieta$Płeć, alternative = 'g', var.equal = TRUE)
# t = -0.49177, df = 70, p-value = 0.6878
# alpha = 0.01

# Wniosek: Na poziomie istotności 0.01 nie ma podstaw do odrzucenia hipotezy h0, zatem wyniki próby nie potwierdzają przypuszczenia, że średnie oceny studentek są wyższe niż studentów studiujących na I roku WI na ZUT w Szczecinie w tym roku akademickim.



# Zadanie 2
# alpha = 0.05

# Test dla dwóch wskaźników struktury

# grupy:
# 1 – grupa mieszkających z rodziną
# 2 – grupa mieszkających poza domem rodzinnym

# wyróżniona cecha: absolewnci TI

# Hipotezy:
# h0 – p1 = p2
# h1 – p1 < p2

table(Ankieta$M.zamieszkania, Ankieta$Sz.średnia)
prop.test(c(15, 20), c(32, 40), alternative = 'l')
# X-squared = 0.00069498, df = 1, p-value = 0.4895
# aplha = 0.05

# Wniosek: na poziomie istotności 0.05 nie można odrzucić hipotezy h0. Zatem odsetki osób, które ukończyły TI nie różnią się istotnie dla mieszkających podczas studiowania z rodziną oraz dla mieszkających poza domem rodzinnym.

# Zadanie 3

# próby zależne

# alpha = 0.01

# założenie: normalność różnicy zmiennych
# h0 – rozkład różnicy zmiennych jest normalny
# h1 – ~h0

x1 = c(225, 236, 312, 238, 241, 196, 205, 259, 218)
x2 = c(216, 195, 245, 235, 221, 170, 180, 265, 179)

shapiro.test(x1 - x2)
# W = 0.96898, p-value = 0.8858

# Wniosek: brak podstaw do odrzucenia h0


# test studenta dla dwóch średnich – próby zależne
# h0 – m1 - m2 = 0
# h1 – m1 - m2 > 0
t.test(x1, x2, paired = T, alternative = 'g')
# t = 3.3633, df = 8, p-value = 0.004942

# Wniosek: na poziomie isotności 0.01 odrzucamy h0 i przyjmujemy h1, zatem leczenie statynami istotnie wpływa na obniżenie poziomu cholesterolu.

# Zadanie 4
# normalność rozkładów -> jednorodność wariancji -> właściwy test

# aplha = 0.01

# założenie 1: normalność rozkładów
# h0 – średni wzrost w populacji studentek jest normalny
# h1 – ~h0

# h0' – średni wzrost w populacji studentów jest normalny
# h1 – ~h0'
by(Ankieta$Wzrost, Ankieta$Płeć, shapiro.test)
# dla kobiet: W = 0.95432, p-value = 0.7197
# dla mężczyzn: W = 0.9598, p-value = 0.04048

# brak podstaw do odrzucenia h0 i h0'

# założenie 2: jednorodność wariancji
# h0 – jednorodność wariancji k.sigma^2 = m.sigma^2
# h1 – ~h0
var.test(Ankieta$Wzrost ~ Ankieta$Płeć)
# F = 1.2842, num df = 9, denom df = 61, p-value = 0.528
# brak podstaw do odrzucenia h0
# będziemy stosować test bez poprawki welcha

# h0 – m.kobiet = m.mężczyzn
# h1 – m.kobiet ≠ m.mężczyzn
t.test(Ankieta$Wzrost ~ Ankieta$Płeć, alternative = 'two.sided', var.equal = T)
# t = -5.2844, df = 70, p-value = 1.36e-06

# Na poziomie istotności 0.01 odrzucamy h0 i przyjmujemy h1.

# zadanie 5
# wskaźnik struktury, grupująca jest płeć

# zadanie 7


# zadanie 8
# alpha = 0.02

# założenie 1: normalność rozkładu
# h0 – rozkład średnich ocen w grupie posiadającej rodzeństwo jest normalny
# h1 – ~h0

# h0' – rozkład średnich ocen w grupie nieposiadającej rodzeństwa jest normalny
# h1' – ~h0'

by(Ankieta$Średnia, Ankieta$Rodzeństwo, shapiro.test)
# nieposiadający rodzeństwa: W = 0.93477, p-value = 0.3929
# posiadający rodzeństwo: W = 0.97486, p-value = 0.26

# brak podstaw do odrzucenia h0 i h0'

# założenie 2: jednorodność wariancji
# h0 – jednorodność wariancji n.sigma^2 = t.sigma^2
# h1 – ~h0
var.test(Ankieta$Średnia ~ Ankieta$Rodzeństwo)
# F = 0.80082, num df = 12, denom df = 58, p-value = 0.704

# brak podstaw do odrzucenia h0
# test bez poprawki welcha

# h0 – m.z_rodzeństwem = m.bez_rodzeństwa
# h1 – m.z_rodzeństwem ≠ m.bez_rodzeństwa
t.test(Ankieta$Średnia ~ Ankieta$Rodzeństwo, alternative = 'two.sided', var.equal = T)
# t = -0.61915, df = 70, p-value = 0.5378

# wniosek: na poziomie istotności 0.02 brak podstaw do odrzucenia h0, że średnia ocen osób posiadających rodzeństwo nie różni istotnie od średniej osób nieposiadających rodzieństwa w badanej grupie.
