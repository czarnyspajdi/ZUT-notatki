# a)

summary(Ankieta$Płeć)
#   Length     Class      Mode 
#       72 character character 

Ankieta$Płeć = factor(Ankieta$Płeć) # ustawiamy płeć na typ kategorialny
# robimy to samo dla pozostałych niemierzalnych cech
Ankieta$Sysytem = factor(Ankieta$System)
Ankieta$M.zamieszkania = factor(Ankieta$M.zamieszkania)
Ankieta$Sz.średnia = factor(Ankieta$Sz.średnia)
Ankieta$Rodzeństwo = factor(Ankieta$Rodzeństwo)

summary(Ankieta$Płeć)

# b)
Ankieta$Średnia = round(((Ankieta$Algebra * 5 + Ankieta$Fizyka * 5 + Ankieta$Programowanie1 * 5 + Ankieta$MSzS1 * 5 + Ankieta$Algorytmy1 * 6 + Ankieta$WdI * 4) / 30), 2);

# c)
Ankieta.kursy = subset(Ankieta, select = c(Algebra, Fizyka, Programowanie1, WdI, MSzS1, Algorytmy1))

# d)
Ankieta$Waga.dag = Ankieta$Waga * 100

# e)
Ankieta$Waga.dag = NULL;

# f)
ggplot(Ankieta, aes(x=Płeć, y=Wzrost))+geom_boxplot(fill='red', col='blue')
ggplot(Ankieta, aes(x=Płeć, y=Waga))+geom_boxplot(fill='red', col='blue')

# g)
zakres3sigm = function(x) {
  data.frame(lewy.kres=mean(x) - 3 * sd(x), prawy.kres=mean(x) + 3 * sd(x))
}

zakres3sigm(Ankieta$Wzrost)

# h)
Ankieta.M = subset(Ankieta, Płeć == 'M')
Ankieta.K = subset(Ankieta, Płeć == 'K')

# i)

# === K ===
zakres3sigm(Ankieta.K$Wzrost)
summary(Ankieta.K$Wzrost)

zakres3sigm(Ankieta.K$Waga)
summary(Ankieta.K$Waga)

# === M ===
zakres3sigm(Ankieta.M$Wzrost)
summary(Ankieta.M$Wzrost)

zakres3sigm(Ankieta.M$Waga)
summary(Ankieta.M$Waga)

which(Ankieta.M$Waga > 126)
Ankieta.M$Waga[28] = round(mean(Ankieta.M$Waga[-28]), 1)

i = which(Ankieta$Waga > 126)
Ankieta$Waga[i] = round(mean(Ankieta.M$Waga[-28]), 1)

# j)

