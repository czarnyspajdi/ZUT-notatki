class Osoba:
    ilosc_osob: int = 0

    def __init__(
        self,
        pesel: str,
        imie: str,
        nazwisko: str,
        wzrost: float = 0.0,
        waga: float = 0.0,
    ) -> None:
        self.__pesel = pesel
        self.__imie = imie
        self.__nazwisko = nazwisko
        self.__wzrost = wzrost
        self.__waga = waga
        Osoba.ilosc_osob += 1

    @property
    def pesel(self) -> str:
        return self.__pesel

    @property
    def imie(self) -> str:
        return self.__imie

    @property
    def nazwisko(self) -> str:
        return self.__nazwisko

    @property
    def wzrost(self) -> float:
        return self.__wzrost

    @wzrost.setter
    def wzrost(self, nowy_wzrost: float) -> None:
        if nowy_wzrost <= 0:
            self.__wzrost = 0
            return
        self.__wzrost = nowy_wzrost

    @property
    def waga(self) -> float:
        return self.__waga

    @waga.setter
    def waga(self, nowa_waga: float) -> None:
        if nowa_waga <= 0:
            self.__waga = 0
            return
        self.__waga = nowa_waga

    @property
    def data_urodzenia(self) -> str:
        return self.__pesel[:6]

    def __del__(self):
        Osoba.ilosc_osob -= 1
        del self

    def __hash__(self) -> int:
        return int(self.__pesel)

    def __str__(self) -> str:
        return f"{self.__pesel}, {self.__imie}, {self.__nazwisko}"

    def __repr__(self):
        return f"Osoba(pesel={self.__pesel}, imie={self.__imie}, nazwisko={self.__nazwisko}, wzrost={self.__wzrost}, waga={self.__waga})"
