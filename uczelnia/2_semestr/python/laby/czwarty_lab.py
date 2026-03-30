from math import sqrt
from collections import namedtuple
import random

# zadanie 1
def getDistance(A: tuple[int, int], B: tuple[int,int]) -> float:
    return sqrt((A[0] - B[0])**2 + (A[1] - B[1])**2)

def analizujProstokat(A: tuple[int, int], B: tuple[int, int]) -> tuple[float, float]:
    a = getDistance((A[0], A[1]), (B[0], A[1]))
    b = getDistance((B[0], A[1]), (B[0], B[1]))

    circuit = a * 2 + b * 2
    field = a * b

    return (circuit, field)

# zadanie 2
def analizujProstokat2(prostokat) -> tuple[float, float]:
    a = getDistance((prostokat.x1, prostokat.y1), (prostokat.x2, prostokat.y1))
    b = getDistance((prostokat.x2, prostokat.y1), (prostokat.x2, prostokat.y2))

    circuit = a * 2 + b * 2
    field = a * b

    return (circuit, field)

def pobieraj_liczby() -> list:
    liczby: list[int] = []
    while True:
        answer = input("Podaj liczbę lub napisz koniec: ")
        if answer == "koniec":
            break
        liczby.append(int(answer))
    liczby.sort(reverse=True)
    return liczby

# zadanie 8
def levenshtein(s: str, t: str):
    d  = [[0 for _ in range(len(s))], [0 for _ in range(len(t))]]
    for i in range(1, len(s) + 1):
        d[i][0] = i
        d[0][i] = i
    for j in range(1, len(t)):
        for i in range(1, len(s)):
            if s[i] == t[j]:
                subsitutionCost = 0
            else:
                subsitutionCost = 1
            d[i][j] = min(d[i - 1][j] + 1, d[i][j - 1] + 1, d[i - 1][j - 1] + subsitutionCost)
    return d

if __name__ == "__main__":
    # zad 1
    print("=== Zadanie 1 ===")
    circuit, field = analizujProstokat((1, 2), (3, 4))
    print(f"Obwód wynosi: {circuit}, a pole: {field}")

    # zad 2
    print("=== Zadanie 2 ===")
    prostokat = namedtuple('prostokat', ['x1', 'y1', 'x2', 'y2'])
    p = prostokat(1, 2, 3, 4)
    circuit, field = analizujProstokat2(p)
    print(f"Obwód wynosi: {circuit}, a pole: {field}")

    # zad 3
    print("=== Zadanie 3 ===")
    lista: list = [i for i in range(1, 6)]
    print(f"Lista przed zamianą: {lista}")
    lista[0], lista[4] = (lista[2], lista[1])
    print(f"Lista po zamianie: {lista}")

    # zad 4
    print("=== Zadanie 4 ===")
    inna_lista: list = [i for i in range(1, 1002, 2)]
    print(f"Inna lista: {inna_lista}")

    # zad 5
    print("=== Zadanie 5 ===")
    print(pobieraj_liczby())

    # zad 6
    print("=== Zadanie 6 ===")
    lista1: list[int] = [i for i in range(0, 11)]
    lista2 = lista1.copy()
    lista2[3] = 234
    print(f"Lista 1: {lista1}")
    print(f"Lista 2: {lista2}")

    # zad 7
    print("=== Zadanie 7 ===")
    lista1 = []
    lista2 = []
    for i in range(10):
        lista1.append(random.randint(0, 10))
        lista2.append(random.random())
    print(lista1)
    print(lista2)
    lista1.extend(lista2)
    print(f"Lista po dodaniu {lista1}")
    print("Próbkowanie:")
    print(random.sample(lista1, 3))

    # zad 8

