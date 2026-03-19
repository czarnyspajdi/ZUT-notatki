from math import log, sin, cos, pi

# zadanie 1

def czas(sekundy):
    godziny = sekundy // 60 // 60
    minuty = sekundy // 60 % 60
    sekundy = sekundy % 60
    return f"{godziny} godzin, {minuty} minut, {sekundy} sekund"

# zadanie 2

def zad2(x, n=10, k=2):
    return log((x**2 + 5), n) * (k + 1) * x

# zadanie 3

zad3 = lambda x: sin(x + 1) + cos(x**4)
zad3_lista = []
for i in range(-5,3):
    print(i)
    zad3_lista.append(zad3(i))

# zadanie 4

def funty_na_kilogramy(funty):
    return funty * 0.45359237

def stopy_na_metry(stopy):
    return stopy * 0.3048

def cale_na_metry(cale):
    return cale * 0.0254

# zadanie 5
def sumuj(*args: int):
    return sum(args)

# zadanie 6
def objetosci(**kwargs):
    print(f"Objętość kuli to: {kwargs['kula_r'] **3 * 4/3 * pi}")
    print(f"Objętość prostopadłościanu to: {kwargs['prostopadloscian_a'] * kwargs['prostopadloscian_b'] * kwargs['prostopadloscian_c']}")
    print(f"Objętość walca to: {kwargs['walec_r'] ** 2 * kwargs['walec_h'] * pi}")
    print(f"Objętość stożka to: {1/3 * pi * kwargs['stozek_r'] ** 2 * kwargs['stozek_h']}")
def kula(**kwargs):
    return kwargs['r'] ** 3 * 4/3 * pi

def prostopadloscian(**kwargs):
    return kwargs['a'] * kwargs['b'] * kwargs['c']

def walec(**kwargs):
    return kwargs['r'] ** 2 * kwargs['h'] * pi

def stozek(**kwargs):
    return 1/3 * pi * kwargs['r'] ** 2 * kwargs['h']


# zadanie 7
def foo(a, b, c):
    pass

def rozpakuj(argumenty: list, argumenty_2: list):
    a, b, c, d = argumenty
    foo(*argumenty_2)

# zadanie 8
def silnia_rek(n: int):
    if n < 1:
        return 1
    return n * silnia_rek(n - 1)

def silnia_ite(n: int): 
    result = 1
    for i in range(2, n + 1):
        result *= i
    return result

# zadanie 9
def tribonaci(n: int):
    if n == 0 or n == 1:
        return 0

    if n == 2:
        return 1

    return tribonaci(n - 1) + tribonaci(n - 2) + tribonaci(n - 3)

# wyświetlanie

print("Zadanie 1:")
print(czas(3599))
print(czas(3601))

print("Zadanie 2:")

print(zad2(2, k=7))

print("Zadanie 3:")
print(zad3_lista)

print("Zadanie 5:")
print(sumuj(2, 4, 8))

print("Zadanie 6:")
objetosci(kula_r = 3, prostopadloscian_a=2, prostopadloscian_b = 3, prostopadloscian_c = 3, walec_r = 2, walec_h = 5, stozek_r = 8, stozek_h = 4)
print(kula(r=3))
print(prostopadloscian(a=2,b=3,c=3))
print(walec(r=2, h=5))
print(stozek(r=8, h=4))


print('Zadanie 8:')
print(f"Silnia rekurencyjnie z 6: {silnia_rek(6)}")
print(f"Silnia iteracyjnie z 6: {silnia_ite(6)}")

print("Zadanie 9:")
print(f"Tribonaci z 5: {tribonaci(5)}")
