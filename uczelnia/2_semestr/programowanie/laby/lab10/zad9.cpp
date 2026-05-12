#include <cstddef>
#include <iostream>
#include <memory>
#include <ostream>
#include <string>
#include <vector>

class Adres {
  std::string ulica;
  int nr_mieszkania;

public:
  Adres(std::string ulica, int nr_mieszkania)
      : ulica(ulica), nr_mieszkania(nr_mieszkania) {}

  friend std::ostream &operator<<(std::ostream &os, Adres &adres) {
    os << adres.ulica << " mieszkania " << adres.nr_mieszkania;
    return os;
  }
};

class Pracownik {
protected:
  std::string imie;
  float pensja;
  std::unique_ptr<Adres> adres;

public:
  virtual float obliczWyplate() = 0;
  Pracownik(std::string imie, float pensja, std::unique_ptr<Adres> adres)
      : imie(imie), pensja(pensja), adres(std::move(adres)) {}
  virtual ~Pracownik() = default;
  friend std::ostream &operator<<(std::ostream &os, Pracownik &p) {
    os << p.imie << " zarabia " << p.obliczWyplate() << " i mieszka na "
       << *(p.adres);
    return os;
  }
};

class PracownikEtatowy : public Pracownik {

public:
  PracownikEtatowy(std::string imie, float pensja, std::unique_ptr<Adres> adres)
      : Pracownik(imie, pensja, std::move(adres)) {}

  float obliczWyplate() override { return pensja; }
};

class Zleceniobiorca : public Pracownik {
  float godziny;

public:
  Zleceniobiorca(std::string imie, float pensja, std::unique_ptr<Adres> adres,
                 float godziny)
      : Pracownik(imie, pensja, std::move(adres)), godziny(godziny) {}
  float obliczWyplate() override { return pensja * godziny; }
};

class Dzial {
  std::vector<std::shared_ptr<Pracownik>> pracownicy;

public:
  Dzial() {};

  void dodajPracownika(std::shared_ptr<Pracownik> pracownik) {
    pracownicy.push_back(pracownik);
  }

  float sumaWyplat() const {
    float sum = 0;
    for (auto &pracownik : pracownicy) {
      sum += pracownik->obliczWyplate();
    }
    return sum;
  }

  void wypiszPracownikow() const {
    std::cout << "=== Wszyscy pracownicy ===\n";
    for (const auto &pracownik : pracownicy) {
      std::cout << *pracownik << std::endl;
    }
  }
};

int main() {
  Dzial dzial = Dzial();
  dzial.dodajPracownika(std::make_shared<PracownikEtatowy>(
      "Bożena", 2500, std::make_unique<Adres>("Żołnierska", 18)));

  dzial.dodajPracownika(std::make_shared<Zleceniobiorca>(
      "Adam", 6700, std::make_unique<Adres>("Wiejska", 1), 30));

  dzial.wypiszPracownikow();
  std::cout << "Pracownicy sumarycznie zarabiają: " << dzial.sumaWyplat();
  return 0;
}
