#include <iostream>
#include <string>

class Produkt {
  double cena;
  int ilosc;

public:
  std::string nazwa;
  Produkt(std::string nazwa, double cena, int ilosc)
      : nazwa(nazwa), cena(cena), ilosc(ilosc) {}
  Produkt() {}

  void wypisz() const {
    std::cout << "Nazwa: " << nazwa << '\n'
              << "Cena: " << cena << '\n'
              << "Ilość: " << ilosc << std::endl;
  }

  double wartosc() const { return cena * ilosc; }
  void zmienCene(double nowaCena) { cena = nowaCena; }
  void dodajSztuke(int ile) { ilosc += ile; }
};

class Magazyn {
  int max_pojemnosc;
  int aktualna_pojemnosc;
  static int ilosc_magazynow;

public:
  Produkt *magazyn;

  Magazyn(int pojemnosc)
      : max_pojemnosc(pojemnosc), magazyn(new Produkt[pojemnosc]),
        aktualna_pojemnosc(0) {}
  ~Magazyn() { delete[] magazyn; }
  bool dodajProdukt(const Produkt &p) {
    if (aktualna_pojemnosc >= max_pojemnosc) {
      return false;
    }
    magazyn[aktualna_pojemnosc++] = p;
    return true;
  }

  Produkt *znajdzProdukt(const std::string &nazwa) {
    for (int i = 0; i < aktualna_pojemnosc; i++) {
      if (magazyn[i].nazwa == nazwa) {
        return &magazyn[i];
      }
    }
    return nullptr;
  }

  void wypiszWszystkie() const {
    for (int i = 0; i < aktualna_pojemnosc; i++) {
      magazyn[i].wypisz();
    }
  }

  double obliczWartoscMagazynu() const {
    double wartosc = 0;
    for (int i = 0; i < aktualna_pojemnosc; i++) {
      wartosc += magazyn[i].wartosc();
    }
    return wartosc;
  }

  static int ileMagazynow() { return Magazyn::ilosc_magazynow; }
};

int Magazyn::ilosc_magazynow = 0;

int main() {
  Magazyn m = Magazyn(10);
  m.dodajProdukt(Produkt("marchewka", 2, 2));
  m.dodajProdukt(Produkt("banan", 5, 3));
  m.dodajProdukt(Produkt("gruszka", 4, 10));
  Produkt *p = m.znajdzProdukt("gruszka");
  p->zmienCene(234);
  m.wypiszWszystkie();
  m.obliczWartoscMagazynu();
  m.ileMagazynow();
}
