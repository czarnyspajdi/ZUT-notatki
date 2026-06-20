#### === LAB 7 Zarządzanie danymi i elementami statystyki opisowej==== ####
# Ogólne manipulowanie zestawem danych

## Wyświetlenie podsumowania danych
### przed faktoryzacją
summary(Ankieta) 
Ankieta$Płeć = factor(Ankieta$Płeć) # <- ustawiamy płeć jako zmienną kategorialną
### po faktoryzacji
summary(Ankieta)

Ankieta$Sysytem = factor(Ankieta$System)
Ankieta$M.zamieszkania = factor(Ankieta$M.zamieszkania)
Ankieta$Sz.średnia = factor(Ankieta$Sz.średnia)
Ankieta$Rodzeństwo = factor(Ankieta$Rodzeństwo)


## Dodanie kolumny
Ankieta$Średnia = round(((Ankieta$Algebra * 5 + Ankieta$Fizyka * 5 + Ankieta$Programowanie1 * 5 + Ankieta$MSzS1 * 5 + Ankieta$Algorytmy1 * 6 + Ankieta$WdI * 4) / 30), 2); # Po prostu wpisujemy co chcemy

## Skopiowanie kolumny z ocenami (subset)
Ankieta$Średnia = round(((Ankieta$Algebra * 5 + Ankieta$Fizyka * 5 + Ankieta$Programowanie1 * 5 + Ankieta$MSzS1 * 5 + Ankieta$Algorytmy1 * 6 + Ankieta$WdI * 4) / 30), 2); # select pozwala wybrac konkretne kolumny poprzez wektor

## Dodanie i likwidacja kolumny
Ankieta$Waga.dag = Ankieta$Waga * 100 # <- dodaje
Ankieta$Waga.dag = NULL # <- likwiduje

# Wykres ramka-wąsy
ggplot(Ankieta, aes(x=Ankieta$Płeć, y=Ankieta$Waga)) + geom_boxplot(fill='red', col='purple') # x – zmienna kategorialna, y – zmienna mierzalna 

## funkcja
zakres3sigm = function(x) {
  data.frame(lewy.kres=mean(x) - 3 * sd(x), prawy.kres=mean(x) + 3 * sd(x))
}

## Podzbiory
Ankieta.M = subset(Ankieta, Ankieta$Płeć == 'M')

Ankieta$L.g.kody = cut(Ankieta$L.godzin, breaks = c(0, 4, 8, 24), labels = c("krótko", "średnio", "długo"), include.lowest = TRUE)
table(Ankieta$L.g.kody)

#### === LAB 8 Parametry opisowe === ####
# zadanie 1

p.opisowe = function(wektor) {
  library(moments)
  srednia = round(mean(wektor), 2)
  mediana = round(median(wektor), 2)
  kwartyl_dolny = round(quantile(wektor, 1/4), 2)
  kwartyl_gorny = round(quantile(wektor, 3/4), 2)
  minimum = round(min(wektor), 2)
  maximum = round(max(wektor), 2)
  odchylenie = round(sd(wektor), 2)
  rozstep_empiryczny = round(max(wektor) - min(wektor), 2)
  rozstep_kwartylowy = round(IQR(wektor), 2)
  wspolczynnik_zmiennosci = round(sd(wektor)/mean(wektor) * 100, 2)
  skosnosc = round(skewness(wektor), 2)
  kurtoza = round(kurtosis(wektor), 2)
  
  rbind(srednia, mediana, kwartyl_dolny, kwartyl_gorny, minimum, maximum, odchylenie, rozstep_empiryczny, rozstep_kwartylowy, wspolczynnik_zmiennosci, skosnosc, kurtoza)
}                                                                        



# zadanie 2
# współczynnik zmienności
# |V| <= 10% – słaba zmienność
# 10% < |V| <= 50% – umiarkowana zmienność
# |V| > 50% – duża zmienność

# skośność (współczynnik asymetrii)
# |G| <= 0.5 – słaba
# 0.5 < |G| < 1 – umiarkowana
# |G| > 1 – duża silna asymetria

# G < 0 – lewostronna
# G > 0 – prawostronna
# G = 0 – symetria (prawie się nie zdarza)

# kurtoza (współczynnik skupienia/spłaczszczenia)
# K = 3 – rozkład normalny
# K < 3 – niższe skupienie niż w rozkładzie normalnym
# K > 3 – wyższe skupienie niż w rozkładzie normalnym


# a)
p.opisowe(Ankieta$Wzrost)
# kwartyl_dolny           174.00 – wzrost 25% mężczyzn nie przekroczył 174
# odchylenie                7.16 – wzrost mężczyzn odchylał się od średniej wzrostu przeciętnie o około 7.16
# wspolczynnik_zmiennosci   3.98 – udział odchylenia standardowego wzrostu w wartości średniej wynosi 3.98 co świadczy o tym, że mężczyźni są słabo zróżnicowani pod względem wzrostu
# skosnosc                  0.20 – rozkład wzrostu mężczyzn charakteryzuje się słabą asymetrią prawostronną

# b)
p.opisowe(Ankieta$Średnia)
# mediana                  3.80 – średnia 50% studentów w badanej grupie nie przekroczyla 3.80
# kwartyl_gorny            4.24 – średnia 75% studentów w badanej grupie nie przekroczyla 4.24

# c)
p.opisowe(Ankieta$L.godzin)
# srednia                  7.07 czas spędzany przy komputerze w badanej grupie skupiał się wokół wartości 7.07
# kurtoza                  2.55 rozklad czasu spędzanego przy komputerze w badanej grupie charakteryzuje się niższym skupieniem wokół średniej wagi niż w rozkładzie normalnym.

# zadanie 3

przedzial.odchylenie = function(x, uf) {
  # 1 - a = uf
  # a = 1 - uf
  a = 1 - uf
  n = length(x)
  ss_z_daszkiem = var(x)
  # s^2 = (n - 1)/n * ss_z_daszkiem
  ss = (n - 1)/n * ss_z_daszkiem
  
  dolna = sqrt((n * ss) / qchisq(1 - (a / 2), n - 1))
  gorna = sqrt((n * ss) / qchisq(a / 2, n - 1))
  round(cbind(dolna, gorna), 4)
}

przedzial.odchylenie(Ankieta.M$Wzrost, 0.95)

# zadanie 4
# a)
ggplot(data.frame(x=c(-4, 4)), aes(x))+ylab('Gęstość rozkładu studenta')+ stat_function(fun=dt, args=1, col='red', size=1) + stat_function(fun=dt, args=2, col='pink', size=1)  + stat_function(fun=dt, args=10, col='green', size=1)  + stat_function(fun=dt, args=50, col='blue', size=1)

# b)
ggplot(data.frame(x=c(-1, 100)), aes(x))+ylab('Gęstość rozkładu chi kwadrat') + stat_function(fun=dchisq, args=5, col='red', size=1) + stat_function(fun=dchisq, args=10, col='blue', size=1) + stat_function(fun=dchisq, args=20, col='green', size=1) + stat_function(fun=dchisq, args=50, col='pink', size=1)


#### === LAB 9 Estymacja i testowanie hipotez dla jednej populacji === ####
# zadanie 1

# a)

# założenie: normalność rozkładu – test shapiro-wilka

# hipoteza podstawowa h0 – rozkład wzrostu w populacji mężczyzn jest normalny
# hipoteza h1 – nieprawda, że h0

shapiro.test(Ankieta.M$Wzrost)
# Statystyka testowa W = 0.9598, p-value = 0.04048
# alpha = 0.01 # poziom istotności
# wniosek alpha < p-value, więc na poziomie istotności 0.01 nie ma podstaw do odrzucenia h0, że rozkład wzrostu w populacji mężczyzn jest zgodny z rozkładem normalnym.

# b)
# przedzial ufności dla wartości średniej w populacji (mężczyzn)
t.test(Ankieta.M$Wzrost, conf.level = 0.95)
#  178.0049 181.6403

# interpretacja: przedział liczbowy od 178.0049 do 181.6403 z prawdopodobieństwem 0.95 obejmuje nieznaną wartość średnią wzrostu w populacji mężczyzn studiujących na pierwszym roku WI ZUT w Szczecinie w tym roku akademickim (2025/2026)

t.test(Ankieta.M$Wzrost, conf.level = 0.98)
#  177.6509 181.9942

przedzial.odchylenie(Ankieta.M$Wzrost, 0.97)
# 5.9801 8.8895

# interpretacja: przedzial o końcach 5.9801 i 8.8895 [cm] z ufnością 0.97 obejmuje rzeczywistą wartość odchylenia standardowego wzrostu w populacji mężczyzn studiujących na pierwszym roku WI ZUT w Szczecinie w tym roku akademickim.

# d)
# test dla wartości średniej w populacji 
# hipoteza h0: m = 180
# hipoteza h1: m > 180
t.test(Ankieta.M$Wzrost, mu = 180, alternative = 'g')
# statystyka testowa t = -0.19518, df = 61, p-value = 0.577
# alpha = 0.01
# alpha < p-value, więc
# na poziomie istotności 0.01 nie ma podstaw do odrzucenia hipotezy h0. Nie można zatem potwierdzić hipotezy, że średni wzrost mężczyzn w badanej populacji jest większy niż 180 cm.


table(Ankieta$Sz.średnia)
# LO(RM) = 22

# a)
# przedział ufności dla odsetka (wskaźnika struktury, frakcji, procentu, proporcji) 
prop.test(22, 72, conf.level = 0.98)
#  0.1909 0.4489
# te końce nie mają jednostek!

# interpretacja: przedział o końcach 0.1909 i 0.4489 z ufnością 0.98 obejmuje rzeczywistą wartość odsetka osób, które ukończyły LO(RM) w badanej populacji.

# b)
# test dla wskaźnika struktury 
# hipoteza h0: p = 45%
# hipoteza h1: p < 45%
prop.test(22, 72, p = 0.45, alternative = 'l')
# statystyka testowa – X-squared = 5.5, df = 1, p-value = 0.009508
# alpha = 0.05
# alpha > p-value, więc
# odrzucamy h0

# Alpha jest większa niż p-value, więc na poziomie istotności 0.05 odrzucamy hipotezę h0 i przyjmujemy h1, zatem odsetek osób, które ukończyły LO(RM) w badanej populacji studentów jest istotnie mniejszy, niż 45%.


# zadanie 3

# a)
# hipoteza h0: rozkład wagi w populacji kobiet jest normalny
# hipotezea h1: rozkład wagi w populacji kobiet nie jest normalny

shapiro.test(Ankieta.K$Waga)
# W = 0.94975, p-value = 0.6656
# alpha = 0.05
# alpha < p-value, więc
# na poziomie istotności 0.05  nie ma podstaw do odrzucenia h0, że rozkład wagi w populacji kobiet jest normalny

# b)
t.test(Ankieta.K$Waga, conf.level = 0.98)
#  49.34915 63.85085

# interpretacja: przedział o końcach 49.34915 i 63.85085 [kg] z ufnością 0.98 zawiera rzeczywistą wartość średniej wagi w populacji wszystkich kobiet studiujących na I roku WI 

# zadanie 4
# a)

table(Ankieta$M.zamieszkania)
# akademik = 23
prop.test(23, 72, conf.level = 0.995)
#  0.1842 0.4918

# interpretacja: przedział o końcach 0.1842 i 0.4918 z ufnością 0.995 obejmuje rzeczywistą wartość odestka osób, które mieszkają w akademiku podczas studiowania  na pierwszym roku kierunku informatyka na WI ZUT w Szczecinie w tym roku akademickim

# b)
# hipoteza h0: p = 0.35
# hipoteza h1: p != 0.35
prop.test(23, 72, p = 0.35, alternative = 'two.sided')
# X-squared = 0.17643, df = 1, p-value = 0.6745
# alpha = 0.05
# alpha < p-value, więc
# odrzucamy h0

# wniosek: Alpha jest mniejsze, niż p-value, więc nie ma podstaw do odrzucenia h0, że odsetek osób, które mieszkają w akademiku w populacji wszystkich studentów I roku na WI różnie się istotnie od 35%
#### === LAB 10 === Testowanie hipotez dla dwóch populacji oraz test dla prób zależnych #### 
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
# wariancje jednorodne = bez poprawki welcha

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


#### === LAB 11 === Testy dla populacji > 3####
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

#### === LAB 12 === Korelacja i regresja, test niezależności chi kwadrat ####
# zadanie 1
# a)

# dwie zmienne mierzalne
x = c(150, 300, 450, 600, 750, 900, 1200, 1500, 1800) # wysokość nad poziomem morza w metrach, zmienna niezależna
y = c(27.2, 26.0, 24.2, 22.5, 21.7, 20.5, 19.0, 17.4, 16) # temperatura powietrza w stopniach celcjusza, zmienna zależna

plot(x, y) # wykres punktów empirycznych

lm(y ~ x) # oszacowanie liniowej funkcji regresji
#   27.322424    -0.006719  
# oszacowana funkcja regresji ma: y = -0.006719x  +  27.322424 

# interpretacja współczynnika regresji: współczynnik regresji równy -0.007 oznacza, że ze wzrostem wysokości nad poziomem morza o jeden metr spada temperatura powietrza średnio o około 0.007 stopnia celcjusza.

abline(lm(y ~ x)) # wykres oszacowanej funkcji regresji

# b)
# istotność współczynnika regresji
# hipotezy:
# h0: ϐ1 = 0
# h1: ~h0

summary(lm(y ~ x))
#                         Estimate Std. Error t value Pr(>|t|)    
# wyraz wolny: (Intercept) 27.3224242  0.4507429   60.62 8.73e-11 ***
# dla x:    x           -0.0067192  0.0004513  -14.89 1.48e-06 ***

# t = -14.89
# p-value = 1.48e-06
# alpha = 0.03
# odrzucamy h0
# Wniosek: Współczynnik regresji między wysokością nad poziomem morza, a temperaturą jest istotnie różny od zera.

# (na kolokwium tylko współczynnik regresji, interpretacja, test)

# zadanie 2
# dwie cechy mierzalne

#a) oszacować współczynnik koleracji i jego interpretacje

cor(Ankieta.K$Waga, Ankieta.K$Wzrost)
# 0.6351466
# Intepretacja współczynnika korelacji: Pomiędzy wagą i wzrostem studentek w badanej grupie istnieje umiarkowana korelacja dodatnia czyli im wyższa osoba tym średnio biorąc większa waga.

# umiarkowana, w tym samym kierunku

# r=0 brak korelacji
# 0<|r|<0.2 bardzo słaba
# 0.2<=|r|<0.4 słaba
# 0.4<=|r|<0.7 umiarkowana
# 0.7<=|r|<0.9 silna
# 0.9<=|r|<1 bardzo silna
# |r|=1 doskonała liniowa
# r > 0 cechy zmieniają się w tym samym kierunku
# r < 0 cechy zmieniają się w przeciwnych kierunkach

# b) przedział ufności dla współczynnika korelacji dla populacji ϱ

cor.test(Ankieta.K$Waga, Ankieta.K$Wzrost, conf.level = 0.95)
# 0.009199008 0.903470512

# Przedział liczbowy od (0.009; 0.903) z prawdopodobieństwem 0.95 obejmuje nieznany współczynnik korelacji między wagą i wzrostem populacji studentek I roku WI ZUT w Szczecinie.


# c) test istotności współczynnika korelacji
# hioptezy:
# h0: ϱ = 0
# h1: ϱ > 0


cor.test(Ankieta.K$Waga, Ankieta.K$Wzrost, alternative = 'g')
# t = 2.3258, df = 8, p-value = 0.02424
# alpha = 0.05

# Odrzucamy h0

# Wniosek: Przy poziomie istotności 0.05 odrzucamy h0, zatem współczynnik korelacji jest istotnie większy od 0.


# Zadanie 3
# dwie cechy niemierzalne
# alpha = 0.01

# hipotezy:
# h0: X, Y są niezależne | zawsze niezależność
# h1: X, Y są zależne


chisq.test(cbind(c(152, 52), c(8, 188)))
# X-squared = 203.67, df = 1, p-value < 2.2e-16
# odrzucamy h0 i przyjmujemy h1

# Wniosek: na poziomie istotności 0.01, zatem można potwierdzić przypuszczenie, że wielkość cebulki wpływa na pojawienie się pędu kwiatostanowego.

# zad 5 c i d | dwie zmienne mierzalne
# wielkość produkcji niezależna
# liczba braków zależna
x = c(0.8, 1.2, 1.6, 1.8, 2.2, 1.6, 2.4, 2.0) # wielkość produkcji w tys. sztuk
y = c(6, 10, 12, 15, 18, 15, 20, 16) # liczba braków

# c)
plot(x, y)
regresja = lm(y ~ x)
#     -0.3438       8.4375  
# y = 8.4375x - 0.3438
abline(regresja)

# Interpretacja: współczynnik regresji równy 8.4375 oznacza, że wzrostem liczby wielkości produkcji o 1 tys. zwiększa się liczba braków o około 8 sztuk.


# d)
# istotność współczynnika regresji
# hipotezy:
# h0: beta1 = 0
# h1: ~h0
summary(regresja)
# t = 12.425
# p-value = 1.66e-05
# alpha = 0.01

# alpha > p-value, odrzucamy h0

# Wniosek: Współczynnik korelacji między wielkością produkcji, a liczbą braków jest istotnie różny od 0. 



