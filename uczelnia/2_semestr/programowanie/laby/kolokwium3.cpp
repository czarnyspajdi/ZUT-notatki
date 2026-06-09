#include <algorithm>
#include <iostream>
#include <memory>
#include <ostream>
#include <stdexcept>
#include <string>
#include <vector>

class Wydawnictwo {
  std::string nazwa, miasto;

public:
  Wydawnictwo(std::string nazwa, std::string miasto)
      : nazwa(nazwa), miasto(miasto) {}

  friend std::ostream &operator<<(std::ostream &os, Wydawnictwo &p) {
    os << "Wydawnictwo o nazwie: " << p.nazwa << ", pochodzi z miasta "
       << p.miasto;
    return os;
  }
};

class Pozycja {
protected:
  std::string tytul;
  double cena;
  int liczba_egzamplarzy;
  Wydawnictwo wydawnictwo;

public:
  Pozycja(std::string tytul, double cena, int liczba_egzamplarzy,
          Wydawnictwo wydawnictwo)
      : tytul(tytul), cena(cena), liczba_egzamplarzy(liczba_egzamplarzy),
        wydawnictwo(wydawnictwo) {}
  virtual ~Pozycja() = default;

  double wartosc() { return liczba_egzamplarzy * cena; }
  void zmienCene(double nowaCena) { cena = nowaCena; }
  std::string getTytul() const { return tytul; }
  virtual std::string kategoria() = 0;
  virtual void wypisz() {
    std::cout << "Pozycja pt. " << tytul << " kosztuje" << cena
              << "\nAktualnie jest " << liczba_egzamplarzy << " takich pozycji."
              << "\nWydawnictwo to: " << wydawnictwo;
  }
  virtual double cenaKoncowa() const = 0;

  friend std::ostream &operator<<(std::ostream &os, Pozycja &p) {
    os << "Tytuł: " << p.tytul << " kosztuje " << p.cenaKoncowa()
       << " i jest kategorii " << p.kategoria() << '\n'
       << "Aktualnie jest " << p.liczba_egzamplarzy << " tej pozycji";
    return os;
  }
};

class Ksiazka : public Pozycja {
  int liczbaStron;

public:
  Ksiazka(std::string tytul, double cena, int liczba_egzamplarzy,
          Wydawnictwo wydawnictwo, int liczbaStron)
      : Pozycja(tytul, cena, liczba_egzamplarzy, wydawnictwo),
        liczbaStron(liczbaStron) {}
  ~Ksiazka() {}

  std::string kategoria() override { return "ksiazka"; }

  double cenaKoncowa() const override {
    if (liczbaStron < 100) {
      return cena - cena * 0.1;
    }
    return cena;
  }

  void wypisz() override {
    wypisz();
    std::cout << "\nLiczba stron wynosi" << liczbaStron << '\n';
  }

  Ksiazka operator+(Ksiazka &p1) {
    Ksiazka nowa_pozycja =
        Ksiazka(tytul, cena, liczba_egzamplarzy + p1.liczba_egzamplarzy,
                wydawnictwo, liczbaStron);
    return nowa_pozycja;
  };
};

class Czasopismo : public Pozycja {
  int numerWydania;

public:
  Czasopismo(std::string tytul, double cena, int liczba_egzamplarzy,
             Wydawnictwo wydawnictwo, int numerWydania)
      : Pozycja(tytul, cena, liczba_egzamplarzy, wydawnictwo),
        numerWydania(numerWydania) {}

  ~Czasopismo() {}

  std::string kategoria() override { return "czasopismo"; }

  double cenaKoncowa() const override {
    if (numerWydania < 12) {
      return cena - cena * 0.2;
    }
    return cena;
  }

  void wypisz() override {
    wypisz();
    std::cout << "\nNumer wydania to: " << numerWydania << '\n';
  }

  Czasopismo operator+(Czasopismo &p1) {
    Czasopismo nowa_pozycja =
        Czasopismo(tytul, cena, liczba_egzamplarzy + p1.liczba_egzamplarzy,
                   wydawnictwo, numerWydania);
    return nowa_pozycja;
  };
};

class Biblioteka {
  std::vector<std::unique_ptr<Pozycja>> pozycje;
  int size;
  static int biblioteka_ammount;

public:
  Biblioteka(int size) : size(size) {
    pozycje.reserve(size);
    biblioteka_ammount++;
  }
  ~Biblioteka() {} // nie musimy ręcznie zwalniać pamięci ponieważ unique_ptr sam
                   // się zwalnia, gdy jego właściciel umiera
  void dodajPozycje(std::unique_ptr<Pozycja> p) {
    pozycje.push_back(std::move(p));
  }

  Pozycja *znajdzPozycje(const std::string &tytul) const {
    for (auto &p : pozycje) {
      if (p->getTytul() == tytul) {
        return p.get();
      }
    }
    return nullptr;
  }

  Pozycja &operator[](int index) {
    if (index < 0 || index >> size) {
      throw std::out_of_range(
          "Index nie może być mniejszy niż zero lub większy niż rozmiar");
    }
    Pozycja *p = pozycje[index].get();
    return *p;
  }

  void sortujWgCeny() { std::sort(pozycje.begin(), pozycje.end()); }

  void wypiszWszystkie() const {
    for (auto &p : pozycje) {
      p->wypisz();
    }
  }

  double obliczWartoscBiblioteki() const {
    double sum = 0;
    for (auto &p : pozycje) {
      sum += p->wartosc();
    }
    return sum;
  }

  int ilePozycjiKategorii(const std::string &kat) {
    int sum = 0;
    for (auto &p : pozycje) {
      if (p->kategoria() == kat) {
        sum++;
      }
    }
    return sum;
  }

  static int ileBibliotek() { return biblioteka_ammount; }
};

int Biblioteka::biblioteka_ammount = 0;

int main() {
  Biblioteka biblioteka = Biblioteka(10);

  Wydawnictwo w1 = Wydawnictwo("Nowa Era", "Szczecin");
  Wydawnictwo w2 = Wydawnictwo("Stara Era", "Warszawa");

  biblioteka.dodajPozycje(
      std::make_unique<Ksiazka>("Ogniem i Mieczem", 12, 10, w1, 360));

  biblioteka.dodajPozycje(
      std::make_unique<Czasopismo>("Telenowele", 2, 1, w2, 3));

  Pozycja *znalezionaPozycja = biblioteka.znajdzPozycje("Ogniem i Mieczem");
  if (!znalezionaPozycja) {
    std::cout << "Nie znaleziono pozycji!!!\n";
    return 1;
  }

  std::cout << "Przed zmianą ceny: " << *znalezionaPozycja << std::endl;
  znalezionaPozycja->zmienCene(123);
  std::cout << "Po zmianie ceny: " << *znalezionaPozycja << std::endl;

  Pozycja *znalezionaPozycja2 = biblioteka.znajdzPozycje("Telenowele");
  if (!znalezionaPozycja) {
    std::cout << "Nie znaleziono pozycji 2!!!\n";
    return 1;
  }

  Ksiazka k1 = Ksiazka("Trala", 23, 12, w1, 1);
  Ksiazka k2 = Ksiazka("Tra", 1, 1, w1, 1);
  std::cout << "\n=== Dodawanie ===\n";
  Ksiazka k3 = k1 + k2;
  std::cout << k1 << std::endl;
  std::cout << k2 << std::endl;
  std::cout << k3 << std::endl;
  std::cout << "\n=== Wyświetlanie ===\n";
  std::cout << "Zerowy element biblioteki: " << biblioteka[0] << std::endl;
  std::cout << "Biblioteka jest warta " << biblioteka.obliczWartoscBiblioteki()
            << std::endl;
  std::cout << "Aktualnie jest " << biblioteka.ilePozycjiKategorii("ksiazka")
            << " książek" << std::endl;
  std::cout << "Aktualnie jest " << biblioteka.ileBibliotek() << " bibliotek"
            << std::endl;
  std::cout << "\n=== Sortowanie ===\n";
  // biblioteka.wypiszWszystkie();
  biblioteka.sortujWgCeny();
  // biblioteka.wypiszWszystkie();
}
