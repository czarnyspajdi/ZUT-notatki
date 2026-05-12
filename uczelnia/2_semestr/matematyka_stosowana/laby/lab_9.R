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

# ze wzrostem współczynnika ufności poszerza się przedział ufności

# c)
# przedział ufności dla odchylenia standardowego w populacji m.

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


# zadanie 2

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