from abc import ABC, abstractmethod
from math import pi as PI


class Figura(ABC):
    @abstractmethod
    def oblicz_pole(self):
        pass

    @abstractmethod
    def typ_figury(self):
        pass

    def print(self):
        print(" Figura : ", self.typ_figury(), " , Pole : ", self.oblicz_pole())

    def __copy__(self):
        cls = self.__class__
        result = cls.__new__(cls)
        result.__dict__.update(self.__dict__)
        return result


class Kwadrat(Figura):
    def __init__(self, a: int | float):
        if isinstance(a, int | float):
            self.a = a
        else:
            raise TypeError("Niewłaściwy typ boku")

    def oblicz_pole(self):
        return self.a**2

    def typ_figury(self):
        return " Kwadrat "


class Kolo(Figura):
    def __init__(self, r: int | float) -> None:
        if isinstance(r, int | float):
            self.r = r
        else:
            raise TypeError("Koło musi mieć r typu liczba !!")

    def oblicz_pole(self) -> float:
        return 2 * PI * self.r

    def typ_figury(self):
        return " Koło "


class Trojkat(Figura):
    def __init__(self, a: int | float, h: int | float):
        if isinstance(a, int | float) and isinstance(h, int | float):
            self.a = a
            self.h = h
        else:
            raise TypeError("Trojkat ma zle typy na wejsciu :((((")

    def oblicz_pole(self) -> float:
        return (self.a * self.h) / 2

    def typ_figury(self):
        return " Trojkat "


if __name__ == "__main__":
    try:
        kwadrat = Kwadrat(3)
        kolo = Kolo(2)
        trojkat = Trojkat(2, 5)
        trojkat2 = trojkat.__copy__()
    except TypeError as e:
        print(f"Bład podczas tworzenia figur: {e}")
    except Exception as e:
        print(f"Nieznany błąd poczas tworzenia figur: {e}")

    kwadrat.print()
    kolo.print()
    trojkat.print()
    trojkat2.print()
