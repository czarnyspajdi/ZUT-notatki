# zadanie 1, kwantyle | kolokwium

# a)

# kwantyl rozkładu normalnego standaryzowanego N(0,1)
qnorm(0.97, 0, 1) # 1.880794
qnorm(0.97) # 1.880794 | wartości 0,1 są domyślne, więc wynik jest taki sam

# b)
qchisq(0.975, 9) # 19.02277

# c)
qt(0.95, 9) # 1.833113

# d)
qf(0.995, 10, 23) # 3.642008

# zadanie 2

# a)
pnorm(2.5, 1.5, 2) # 0.6914625
round(pnorm(2.5, 1.5, 2), 4) # zaokrąglony wynik do 4 miejsc po przecinku: 0.6915

# b)
round(pnorm(-0.5, 1.5, 2, F), 4) # 0.8413

# c)
round(pnorm(2, 1.5, 2) - pnorm(0.5, 1.5, 2), 4) # 0.2902

# d) na kolokwium będzie z abs
round(pnorm(5, 1.5, 2) - pnorm(-1, 1.5, 2),4) # 0.8543

# e)
round(pnorm(-0.5, 1.5, 2) + pnorm(0.5,1.5,2, F),4) # 0.8501

# f)
# |2x - 1| < 1
# -1 < 2x - 1 < 1
# 0 < 2x < 2
# 0 < x < 1
round(pnorm(1, 1.5, 2) - pnorm(0, 1.5 ,2),4) # 0.1747

# g)
# |3x - 1| > 2
# 3x - 1 < -2 && 3x -1 > 2
# 3x < -1 && 3x > 3
# x < -1/3 && x > 1
round(pnorm(-1/3, 1.5, 2) + pnorm(1, 1.5, 2, F), 4) # 0.7784

# zadanie 3
# na kolokwium będzie b) i d)

# a)
# 2x > -4.5
# 2 > -2.25
round(pnorm(-2.25, -4, 3.5, F), 4) # 0.3085

# b)
# |5x - 1| > 2.5
# 5x - 1 < -2.5 || 5x - 1 > 2.5
# 5x < -1.5 || 5x > 3.5
# -0.3 < -0.75 || x > 0.7
round(pnorm(-0.3, -4, 3.5) + pnorm(0.7, -4, 3.5, F), 4) # 0.9444

# c)
# -8 < 3x + 1 < 2
# -9 < 3x < 1
# -3 < x < 1/3
round(pnorm(1/3, -4, 3.5) - pnorm(-3, -4, 3.5), 4) # 0.2797

# d)
pnorm(7.5/4, -4, 3.5) - pnorm(-3.5/4, -4, 3.5) #0.139349

# zadanie 4 | N(1000, 50)

# a)
round(pnorm(900, 1000, 50) * 4000) # 91

# b)
qnorm(0.13, 1000, 50, F) # 1056.32

# zadanie 5 | N(6.8, 0.3)

# a)
round(pnorm(7.1, 6.8, 0.3) * 30) # 25

# b)
qnorm(0.15, 6.8, 0.3) # 6.48907

# zadanie 6 | N(15, 13)

# a) 22,05 < x < 22,10
(pnorm(10,15,13)-pnorm(5,15,13)) # 0.129383

# b)
pnorm(20,15,13,F) # 0.3502612

# zadanie 7 | N(20,5)
#a) p = 0.8849  X < k1
qnorm(0.8849, 20, 5)
#25.99922

#b) p =0.6554  X > k2
qnorm(0.6554, 20, 5, F)
#18.0003

# c)
20 - qnorm((1 - 0.6554) / 2, 20, 5) # 4.725577

# d)
20 - qnorm(0.00511/2, 20, 5) #14.00008
