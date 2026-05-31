#include <iostream>
#include <memory>
#include <ostream>
#include <string>
#include <vector>

class Producent {
  std::string nazwa, kraj;

public:
  Producent(std::string nazwa, std::string kraj) : nazwa(nazwa), kraj(kraj) {}

  friend std::ostream &operator<<(std::ostream &os, const Producent &p) {
    os << "Producent o nazwie " << p.nazwa << " z kraju " << p.kraj;
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
  Towar(std::string nazwa, double cena, int sztuki, const Producent &producent)
      : nazwa(nazwa), cena(cena), sztuki(sztuki), producent(producent) {}

  virtual ~Towar() = default;
  double wartosc() const { return cena * sztuki; }
  void zmienCene(double nowaCena) { cena = nowaCena; }
  void dodajSztuki(int ile) { sztuki += ile; }

  std::string getNazwa() const { return nazwa; }

  virtual std::string kategoria() const = 0;

  virtual void wypisz() const {
    std::cout << "Nazwa: " << nazwa << ", Cena jedn.: " << cena
              << ", Sztuk: " << sztuki << ", " << producent;
  }

  virtual double cenaKoncowa() const = 0;

  int operator+(const Towar &t) const { return sztuki + t.sztuki; }

  friend std::ostream &operator<<(std::ostream &os, const Towar &t) {
    os << t.nazwa << " należy do kategorii " << t.kategoria() 
       << " i kosztuje w sumie " << t.cenaKoncowa();
    return os;
  }
};

class TowarSpozywczy : public Towar {
  std::string terminWaznosci;

public:
  TowarSpozywczy(std::string nazwa, double cena, int sztuki,
                 const Producent &producent, std::string terminWaznosci)
      : Towar(nazwa, cena, sztuki, producent), terminWaznosci(terminWaznosci) {}
  ~TowarSpozywczy() {}

  std::string kategoria() const override { return "spożywczy"; }
  double cenaKoncowa() const override {
    int rabat = 10;
    return wartosc() - rabat;
  }
  void wypisz() const override {
    Towar::wypisz();

    std::cout << ", termin ważności do " << terminWaznosci;
  }
};

class TowarElektroniczny : public Towar {
  int gwarancja;

public:
  TowarElektroniczny(std::string nazwa, double cena, int sztuki,
                     const Producent &producent, int gwarancja)
      : Towar(nazwa, cena, sztuki, producent), gwarancja(gwarancja) {}
  ~TowarElektroniczny() {}

  std::string kategoria() const override { return "elektronika"; }
  double cenaKoncowa() const override {
    int koszt_gwarancji = 67;
    return wartosc() + koszt_gwarancji;
  }

  void wypisz() const override {
    Towar::wypisz();
    std::cout << ", gwarancja na " << gwarancja << " miesięcy";
  }
};

class Sklep {
  std::vector<std::unique_ptr<Towar>> towary;
  int max_towar, current_towar;
  static int SKLEP_AMMOUNT;

public:
  Sklep(int max) : max_towar(max), current_towar(0) {
    towary.reserve(max);
    SKLEP_AMMOUNT++;
  }
  ~Sklep() { towary.clear(); }

  bool dodajTowar(std::unique_ptr<Towar> t) {
    towary.push_back(std::move(t));
    return true;
  }

  Towar *znajdzTowar(const std::string &nazwa) {
    for (auto &towar : towary) {
      if (towar->getNazwa() == nazwa) {
        return towar.get();
      }
    }
    return nullptr;
  }

  void wypiszWszystkie() const {
    for (auto &towar : towary) {
      towar->wypisz();
      std::cout << "\n";
    }
  }

  double obliczWartoscSklepu() const {
    double sum = 0;
    for (const auto &towar : towary) {
      sum += towar->cenaKoncowa();
    }
    return sum;
  }

  int ileTowarowKategorii(const std::string &kat) const {
    int sum = 0;
    for (const auto &towar : towary) {
      if (towar->kategoria() == kat) {
        sum++;
      }
    }
    return sum;
  }

  static int ileSklepow() { return SKLEP_AMMOUNT; }
};

int Sklep::SKLEP_AMMOUNT = 0;

int main() {
  Sklep sklep = Sklep(10);
  Producent producent1 = Producent("Rafał Brzoska", "Polska");
  Producent producent2 = Producent("Jeff Bezos", "Afryka");

  sklep.dodajTowar(
      std::make_unique<TowarSpozywczy>("burak", 20, 5, producent1, "67 lat"));

  sklep.dodajTowar(
      std::make_unique<TowarElektroniczny>("komputer", 20, 5, producent2, 24));

  Towar *znalezionyTowar = sklep.znajdzTowar("burak");

  Towar *znalezionyTowar2 = sklep.znajdzTowar("komputer");

  if (znalezionyTowar)
    znalezionyTowar->zmienCene(1);

  if (znalezionyTowar && znalezionyTowar2) {
    int wynik = *znalezionyTowar + *znalezionyTowar2;
    std::cout << wynik << std::endl;
  }

  if (znalezionyTowar)
    std::cout << *znalezionyTowar << std::endl;

  if (znalezionyTowar2)
    std::cout << *znalezionyTowar2 << std::endl;

  std::cout << sklep.obliczWartoscSklepu() << std::endl;
  std::cout << sklep.ileTowarowKategorii("spożywczy") << std::endl;
  std::cout << sklep.ileSklepow() << std::endl;

  return 0;
}
