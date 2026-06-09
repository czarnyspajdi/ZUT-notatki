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



  