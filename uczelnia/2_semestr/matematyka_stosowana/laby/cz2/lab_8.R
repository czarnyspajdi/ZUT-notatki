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
