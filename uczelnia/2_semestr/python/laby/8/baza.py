from osoba import Osoba
from pracownik import Pracownik

if __name__ == "__main__":
    baza: set[Pracownik | Osoba] = set()

    baza.add(Osoba("2342348", "Bogdan", "Wojciechowski", 67.67, 69.69))
    baza.add(Osoba("2983473", "Stanisław", "Pięta", 123.21, 543.23))
    baza.add(Osoba("2389412", "Stefan", "Cichnicki", 67.67, 233.1))
    baza.add(Osoba("2983473", "Genowefa", "Pięta", 123.21, 543.23))
    baza.add(Osoba("2389412", "Aniela", "Głąb", 2384.1, 233.1))

    baza.add(
        Pracownik(
            "2389412",
            "Stanisław",
            "Lem",
            "Wydawnictwo niezwykłe",
            2384.1,
            233.1,
            234123,
        )
    )

    baza.add(
        Pracownik("2389412", "Andrzej", "Sapkowski", "CD PROJEKT RED", 2384.1, 233.1, 5)
    )
    baza.add(
        Pracownik(
            "2389412", "Andrzej", "Duda", "Pałac prezydencki", 2384.1, 233.1, 234123
        )
    )

    for element in baza:
        print(element.__repr__())
