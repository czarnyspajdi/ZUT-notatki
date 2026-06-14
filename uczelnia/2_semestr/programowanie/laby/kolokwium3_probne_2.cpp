#include <exception>
#include <iostream>
#include <memory>
#include <ostream>
#include <string>
#include <vector>

class Producent {
  std::string nazwa;
  std::string kraj;

public:
  Producent(std::string nazwa, std::string kraj) : nazwa(nazwa), kraj(kraj) {}

  friend std::ostream &operator<<(std::ostream &os, const Producent p) {
    os << "Nazwa: " << p.nazwa << " pochodzi z kraju: " << p.kraj;
    return os;
  }
};

class Towar {
protected:
  std::string nazwa;
  double cena;
  int sztuki;
  Producent producent;

public:
  Towar(std::string nazwa, double cena, int sztuki, Producent producent)
      : nazwa(nazwa), cena(cena), sztuki(sztuki), producent(producent) {}
  virtual ~Towar() = default;

  double wartosc() const { return cena * sztuki; }

  void zmienCene(double nowaCena) { cena = nowaCena; }

  virtual std::string kategoria() = 0;

  virtual void wypisz() const {
    std::cout << "Nazwa: " << nazwa << " kosztuje " << cena
              << ". Aktualnie jest " << sztuki << " sztuk. Producent to "
              << producent << std::endl;
  }

  virtual double cenaKoncowa() const = 0;

  int operator+(Towar &t) { return sztuki + t.sztuki; }

  friend std::ostream &operator<<(std::ostream &os, Towar &t) {
    os << "Nazwa: " << t.nazwa << " kosztuje " << t.cenaKoncowa()
       << ". Aktualnie jest " << t.sztuki << " sztuk. Producent to "
       << t.producent;
    return os;
  }
};

class TowarSpozywczy : public Towar {
  std::string terminWaznosci;

public:
  TowarSpozywczy(std::string nazwa, double cena, int sztuki,
                 Producent producent, std::string terminWaznosci)
      : Towar(nazwa, cena, sztuki, producent), terminWaznosci(terminWaznosci) {}

  std::string kategoria() override { return "spozywczy"; }
  double cenaKoncowa() const override {
    int rabat = 5;
    return wartosc() - rabat;
  }

  void wypisz() const override {
    wypisz();
    std::cout << "Termin ważności jest do " << terminWaznosci << std::endl;
  }
};

class TowarElektroniczny : public Towar {
  int gwarancjaMiesiace;

public:
  TowarElektroniczny(std::string nazwa, double cena, int sztuki,
                     Producent producent, int gwarancjaMiesiace)
      : Towar(nazwa, cena, sztuki, producent),
        gwarancjaMiesiace(gwarancjaMiesiace) {}

  std::string kategoria() override { return "spozywczy"; }
  double cenaKoncowa() const override {
    int koszt_gwarancji = 10;
    return wartosc() + koszt_gwarancji;
  }

  void wypisz() const override {
    wypisz();
    std::cout << "Gwarancja trwa" << gwarancjaMiesiace << " miesięcy."
              << std::endl;
  }
};

class Sklep {
  std::vector<std::unique_ptr<Towar>> towary;
  int max;
  int current;

  static int liczba_sklepow;

public:
  Sklep(int max) : max(max), current(0) { towary.reserve(max); }
};

int Sklep::liczba_sklepow = 0;
