from itertools import product
from collections import Counter, defaultdict, deque

# zadanie 1

def zad1():
    tekst = """Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt
ut labore et dolore magna aliqua. Dolor sed viverra ipsum nunc aliquet bibendum enim. In
massa tempor nec feugiat. Nunc aliquet bibendum enim facilisis gravida. Nisl nunc mi ipsum
faucibus vitae aliquet nec ullamcorper. Amet luctus venenatis lectus magna fringilla. Volut-
pat maecenas volutpat blandit aliquam etiam erat velit scelerisque in. Egestas egestas fringilla
phasellus faucibus scelerisque eleifend. Sagittis orci a scelerisque purus semper eget duis. Nulla
pharetra diam sit amet nisl suscipit. Sed adipiscing diam donec adipiscing tristique risus nec
feugiat in. Fusce ut placerat orci nulla. Pharetra vel turpis nunc eget lorem dolor. Tristique
senectus et netus et malesuada.
"""
    wyrazy: set = set()
    
    for word in tekst.lower().replace(".", "").replace(",", "").strip().split(" "):
        wyrazy.add(word)
    print(wyrazy)

# zadanie 2

def zad2():
    A = {1, 2, 3, 4, 5}
    B = {2, 4, 5}

    if A < B: print("A jest podzbiorem B")
    if A > B: print("A jest nadzbiorem B")

    print(f"Przecięcie: {A.intersection(B)}")
    print(f"Suma: {A.union(B)}")
    print(f"Różnica: {A.difference(B)}")
    print(f"Różnica symetryczna: {A.symmetric_difference(B)}")

# zadanie 3
def zad3():
    A = {1, 2, 3, 4, 5}
    B = {2, 4, 5}
    print(f"Iloczyn kartezjański: {list(product(A, B))}")

def zad3_wlasne():
    A = {1, 2, 3, 4, 5}
    B = {2, 4, 5}
    iloczyn: set = set()
    for x in A:
        for y in B:
            iloczyn.add((x,y))
    print(f"Iloczyn kartezjański: {iloczyn}")



# zadanie 4
def zad4():
    urodziny: dict = {}
    while True:
        name = input("Podaj nazwisko (lub wpisz koniec by zakończyć): ")
        if name == "koniec":
            return

        if name in urodziny:
            print(f"Urodziny odbędą się: {urodziny[name]}")
        else:
            urodziny[name] = input("Taki wpis nie istnieje. Podaj datę urodzin: ")

# zadanie 5
def zad5():
    slownik: dict = {
            "1" : "jeden",
            "2" : "dwa",
            "3" : "trzy",
            "4" : "cztery",
            "5" : "pięć",
            "6" : "sześć",
            "7" : "siedem",
            "8" : "osiem",
            "9" : "dziewięć",
            }
    tekst = input("Podaj liczbę od 1 do 99: ")
    if tekst == "10":
        result = "dziesięć"
        print(result)
        return

    result = slownik[tekst[0]]
    if len(tekst) > 1:
        match tekst[0]:
            case "1":
                result = f"{slownik[tekst[1]]}naście"
                print(result)
                return
            case "2":
                result += "dzieścia"
            case "3" | "4":
                result += "dzieści"
            case "5" | "6" | "7" | "8" | "9":
                result += "dziesiąt"
        
        if tekst[1] != "0":
            result += f" {slownik[tekst[1]]}"
    print(result)

# zadanie 6
def zad6():
    tekst = """Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt
ut labore et dolore magna aliqua. Dolor sed viverra ipsum nunc aliquet bibendum enim. In
massa tempor nec feugiat. Nunc aliquet bibendum enim facilisis gravida. Nisl nunc mi ipsum
faucibus vitae aliquet nec ullamcorper. Amet luctus venenatis lectus magna fringilla. Volut-
pat maecenas volutpat blandit aliquam etiam erat velit scelerisque in. Egestas egestas fringilla
phasellus faucibus scelerisque eleifend. Sagittis orci a scelerisque purus semper eget duis. Nulla
pharetra diam sit amet nisl suscipit. Sed adipiscing diam donec adipiscing tristique risus nec
feugiat in. Fusce ut placerat orci nulla. Pharetra vel turpis nunc eget lorem dolor. Tristique
senectus et netus et malesuada.
"""
    wyrazy: Counter = Counter()
    
    for word in tekst.lower().replace(".", "").replace(",", "").strip().split(" "):
        wyrazy[word] += 1
    print(wyrazy)
    
# zadanie 7
def zad7():
    slownik: defaultdict = defaultdict(lambda: 5)
    for _ in range(5):
        klucz = input("Podaj klucz: ")
        print(f"Aktualna wartość pod kluczem: {klucz} to: {slownik[klucz]}")
        slownik[klucz] += 1

# zadanie 8
def zad8():
    wyrazy: deque = deque(input("Podaj wyraz: "))
    if wyrazy.popleft() != wyrazy.pop():
        print("Wyraz nie jest palindromem!")
        return
    print("Wyraz jest palindromem")


if __name__ == "__main__":
    zad3()
    zad3_wlasne()
