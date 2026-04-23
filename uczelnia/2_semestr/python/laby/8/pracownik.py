from osoba import Osoba


class Pracownik(Osoba):
    def __init__(
        self,
        pesel: str,
        imie: str,
        nazwisko: str,
        miejsce_zatrudnienia: str,
        wzrost: float = 0.0,
        waga: float = 0.0,
        pensja: float = 0.0,
    ) -> None:
        super().__init__(pesel, imie, nazwisko, wzrost, waga)
        self.__miejsce_zatrudnienia = miejsce_zatrudnienia
        self.__pensja = pensja

    @property
    def miejsce_zatrudnienia(self) -> str:
        return self.__miejsce_zatrudnienia

    @miejsce_zatrudnienia.setter
    def miejsce_zatrudnienia(self, nowe_miejsce: str):
        if nowe_miejsce:
            self.__miejsce_zatrudnienia = nowe_miejsce
            return
        nowe_miejsce = ""

    @property
    def pensja(self) -> float:
        return self.__pensja

    @pensja.setter
    def pensja(self, nowa_pensja: float) -> None:
        if nowa_pensja >= 0:
            self.__pensja = nowa_pensja
            return
        self.__pensja = 0

    def __str__(self):
        return f"{super().__str__()} | Miejsce zatrudnienia: {self.__miejsce_zatrudnienia} "

    def __repr__(self):
        return f"Pracownik(pesel={super().pesel}, imie={super().imie}, nazwisko={super().nazwisko}, miejsce_zatrudnienia={self.miejsce_zatrudnienia}, wzrost={super().wzrost}, waga={super().waga}, pensja={self.pensja})"
