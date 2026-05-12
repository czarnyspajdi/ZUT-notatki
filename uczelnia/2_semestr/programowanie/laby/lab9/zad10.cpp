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
  ~Biblioteka() {
    delete[] ksiazki;
    ksiazki = nullptr;
  }

  void dodajKsiazke(Ksiazka k) { ksiazki[aktualna_ksiazka++] = k; }

  Ksiazka *szukajPoTytule(std::string tytul) const {
    for (int i = 0; i < aktualna_ksiazka; i++) {
      if (ksiazki[i].tytul == tytul) {
        return &ksiazki[i];
      }
    }
    return nullptr;
  }

  void wypiszWszystkie() const {
    for (int i = 0; i < aktualna_ksiazka; i++) {
      std::cout << ksiazki[i] << '\n';
    }
  }
};

class Osoba {
  std::string imie;

public:
  Osoba(std::string imie) : imie(imie) {}
};

class Czytelnik : public Osoba { // dziedziczenie
  Ksiazka *ksiazki;              // agregacja
  const int max_ilosc;
  int aktualna_ilosc_ksiazek = 0;

public:
  Czytelnik(std::string imie, size_t max_ilosc)
      : Osoba(imie), max_ilosc(max_ilosc), ksiazki(new Ksiazka[max_ilosc]) {}
  ~Czytelnik() {
    delete[] ksiazki;
    ksiazki = nullptr;
  }

  void wypozycz(Biblioteka &biblioteka, std::string tytul) {
    Ksiazka *ksiazka = biblioteka.szukajPoTytule(tytul);
    if (!ksiazka) {
      std::cout << "Nie znaleziono książki pt." << tytul << " w bibliotece!"
                << std::endl;
      return;
    }
    ksiazki[aktualna_ilosc_ksiazek++] = *ksiazka;
  }
  void wypiszWszystkie() const {
    for (int i = 0; i < aktualna_ilosc_ksiazek; i++) {
      std::cout << ksiazki[i];
    }
  }
};

int main() {
  Biblioteka b = Biblioteka(12);
  std::string tytul = "Ogniem i mieczem";
  Ksiazka k1 = Ksiazka(tytul, "1920", Autor("Henryk", "Sienkiewicz"));
  b.dodajKsiazke(k1);
  std::cout << "===\n";
  std::cout << "Książki biblioteki: " << std::endl;
  b.wypiszWszystkie();
  Czytelnik czytelnik = Czytelnik("Bogdan", 8);
  std::cout << "===\n";
  std::cout << "Książki czytelnika: " << std::endl;
  czytelnik.wypozycz(b, tytul);
  czytelnik.wypozycz(b, "Hobbit");
  czytelnik.wypiszWszystkie();
}
