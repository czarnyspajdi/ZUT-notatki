#imie = input("Jak masz na imie: ")
#print("Witaj, ", imie)
#
#kierunek = str(input("Podaj kierunek studiów: "))
#rok = int(input("Podaj rok studiów: "))
#srednia = float(input("Podaj średnią swoją: "))
#print(f"Kierunek: {kierunek}\nRok studiów: {rok}\nŚrednia: {srednia}")
#
#adres = str(input("Podaj adres zamieszkania: "))
#kod_pocztowy = str(input("Podaj kod pocztowy: "))
#miasto = str(input("Podaj miasto: "))
#print(adres, kod_pocztowy, miasto, sep=",")
#
wzrost = int(input("Podaj swój wzrost: "))
waga = int(input("Podaj swoją wagę: "))

wzrost_m = float(wzrost / 100)
waga_kg = float(waga / 1000)
bmi = waga_kg/(wzrost_m**2)
print(f"Wzrost: {wzrost_m}m\nWaga: {waga_kg}kg\nBmi wynosi: {bmi}")

liczba: bool = int(input("Podaj liczbę: ")) > 10 

inna_liczba = int(input("Podaj inną liczbę: "))
pierwszy_warunek_innej_liczby = 10 < inna_liczba < 20
drugi_warunek_innej_liczby = inna_liczba < 0 or inna_liczba > 20

# to jest komentarz

"""
komentarz wieloniowy
"""

