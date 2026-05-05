#include <cstddef>
#include <iostream>
#include <ostream>
#include <string>

class Autor {

public:
  std::string imie, nazwisko;
  Autor(std::string imie, std::string nazwisko)
      : imie(imie), nazwisko(nazwisko) {}
  Autor() {}
};

class Ksiazka {
public:
  std::string tytul, rok;
  Autor autor;
  Ksiazka(std::string tytul, std::string rok, Autor autor)
      : tytul(tytul), rok(rok), autor(autor) {}
  Ksiazka() {}
  friend std::ostream &operator<<(std::ostream &os, Ksiazka k) {
    os << "Tytuł: " << k.tytul << "\nRok wydania: " << k.rok
       << "\nAutor: " << k.autor.imie << ' ' << k.autor.nazwisko;
    return os;
  }
};

class Biblioteka {
  Ksiazka *ksiazki;
  int aktualna_ksiazka = 0;

public:
  Biblioteka(size_t size) : ksiazki(new Ksiazka[size]) {}

  void dodajKsiazke(Ksiazka k) { ksiazki[aktualna_ksiazka++] = k; }

  Ksiazka *szukajPoTytule(std::string tytul) {
    for (int i = 0; i < aktualna_ksiazka; i++) {
      if (ksiazki[i].tytul == tytul) {
        return &ksiazki[i];
      }
    }
    return nullptr;
  }

  void wypiszWszystkie() {
    for (int i = 0; i < aktualna_ksiazka; i++) {
      std::cout << ksiazki[i];
    }
  }
};

class Osoba {
  std::string imie;

public:
  Osoba(std::string imie) : imie(imie) {}
};

class Czytelnik : Osoba { // dziedziczenie
  Ksiazka *ksiazki;       // agregacja
  const int max_ilosc;
  int aktualna_ilosc_ksiazek = 0;

public:
  Czytelnik(std::string imie, size_t max_ilosc)
      : Osoba(imie), max_ilosc(max_ilosc), ksiazki(new Ksiazka[max_ilosc]) {}
  void wypozycz(Ksiazka ksiazka) {
    if (aktualna_ilosc_ksiazek < max_ilosc) {
      ksiazki[aktualna_ilosc_ksiazek++] = ksiazka;
    }
  }
  void wypiszWszystkie() {
    for (int i = 0; i < aktualna_ilosc_ksiazek; i++) {
      std::cout << ksiazki[i];
    }
  }
};

int main() {
  Biblioteka b = Biblioteka(12);
  Ksiazka k1 =
      Ksiazka("Ogniem i Mieczem", "1920", Autor("Henryk", "Sienkiewicz"));
  b.dodajKsiazke(k1);
  std::cout << "Książki biblioteki: "<<  std::endl;
  b.wypiszWszystkie();
  Czytelnik czytelnik = Czytelnik("Bogdan", 8);
  std::cout << "Książki czytelnika: "<<  std::endl;
  czytelnik.wypozycz(k1);
  czytelnik.wypiszWszystkie();
}
