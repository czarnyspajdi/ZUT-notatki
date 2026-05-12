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
  int const max_Ksiazki;

public:
  Biblioteka(size_t size) : ksiazki(new Ksiazka[size]), max_Ksiazki(size) {}
  ~Biblioteka() {
    delete[] ksiazki;
    ksiazki = nullptr;
  }

  void dodajKsiazke(Ksiazka k) {
    if (aktualna_ksiazka < max_Ksiazki) {
      ksiazki[aktualna_ksiazka++] = k;
    }
  }

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
      std::cout << ksiazki[i] << '\n';
    }
  }
};

int main() {
  Biblioteka b = Biblioteka(10);
  Ksiazka k1 =
      Ksiazka("Miecz przeznaczenia", "1920", Autor("Andrzej", "Sapkowski"));
  Ksiazka k2 = Ksiazka("Dziki gon", "1800", Autor("Andrzej", "Sapkowski"));

  b.dodajKsiazke(k1);
  b.dodajKsiazke(k2);
  Ksiazka *znalezionaKsiazka = b.szukajPoTytule("Miecz przeznaczenia");
  if (!znalezionaKsiazka) {
    return 1;
  }
  std::cout << "Znaleziona książka to: " << *znalezionaKsiazka << std::endl;
  std::cout << "=== Wszystkie książki ===" << std::endl;
  b.wypiszWszystkie();
}
