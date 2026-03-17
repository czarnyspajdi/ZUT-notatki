import random

# zadanie 1

def zad1():
    lista = [0, -2, 1, 7, 3, 4]
    print(lista[::-1])

    losowa_lista = [random.randint(1,100) for i in range(100)]
    print(f"Cała lista: {losowa_lista}")
    print(f"Odwrócona lista: {losowa_lista[::-1]}")

# zadanie 2
def zad2():
    import math
    x = float(input("Podaj x: "))
    y = float(input("Podaj y: "))

    result = math.e + math.log10(x**2 + 1) * (x-1)/(math.cos(y**3 - 1) + 6)
    print(f"Wynikiem skomplikowanych obliczeń jest: {result}")

# dla 2, 4 = 2.8183362733213935
# dla -9.5, 6.4 = -1.3367487551407415

def obliczenia_zad3():
    x = int(input("Podaj x: "))
    y = int(input("Podaj y: "))
    z = int(input("Podaj z: "))
    c = int(input("Podaj c: "))

    match c:
        case 1: # suma
            return x + y + z
        case 2: # różnica
            return x - y - z
        case 3: # iloczyn
            return x * y * z
        case _:
            if y == 0:
                raise ValueError("Nie dzielimy przez zero!")
            return x / y / z

def zad3():
    try:
        print(obliczenia_zad3())
    except ValueError as e:
        print(e)

def zad4():
    waga = float(input("Podaj wagę w kg: "))
    wzrost = float(input("Podaj wzrost w m: "))
    bmi = waga/wzrost**2
    if bmi < 16:
        print("Jesteś wygłodzony!")
    elif bmi >= 16 and bmi < 17:
        print("Jesteś wychudzony!")
    elif bmi >= 17 and bmi < 18.5:
        print("Masz niedowagę!")
    elif bmi >= 18.5 and bmi < 25:
        print("Jesteś w normie!")
    elif bmi >= 25 and bmi < 30:
        print("Masz nadwagę!")
    elif bmi >= 30 and bmi < 35:
        print("Otyłość I stopnia")
    elif bmi >= 35 and bmi < 40:
        print("Otyłość II stopnia")
    elif bmi >= 40:
        print("Otyłość III stopnia")

def zad5():
    for i in range(1, 5):
        print("*" * i)

def zad6():
    macierz =[[i for i in range(1, 8, 3)]] * 3
    print(macierz)

def zad7():
    n = int(input("Podaj zakres do którego szukamy liczb pierwszych: "))
    prime_numbers = []
    if n == 3:
        prime_numbers.append(n)
        print(f"Liczby pierwsze do {n} to: {prime_numbers}")
        return

    for i in range(2, n):
        is_prime = True
        for j in range(2, i - 1):
            if i % j == 0:
                print(f"{i} dzieli się przez {j}")
                is_prime = False
                continue
        if is_prime:
            prime_numbers.append(i)

    print(f"Liczby pierwsze do {n} to: {prime_numbers}")
    print(len(prime_numbers))

def zad8():
    n = int(input("Podaj n: "))
    numbers = []
    for i in range(1, n + 1):
        if i % 10 == 3 or i % 100 == 14:
            numbers.append(i)
    print(f"Suma liczb naturalnych do {n} zakończonych na 3 lub 14 to {sum(numbers)}")

def wyswietl(list):
    print(' '.join([str(item) for item in list]).center(30))

def zad9():
    n = int(input("Podaj n: "))
    rzad = [1]
    wyswietl(rzad)

    for _ in range(n - 1):
        kolejny_rzad = [1]
        for j in range(len(rzad) - 1):
            kolejny_rzad.append(rzad[j] + rzad[j + 1])
        kolejny_rzad.append(1)
        rzad = kolejny_rzad
        wyswietl(rzad)


if __name__ == "__main__":
    zad9()
