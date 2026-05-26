#include <iostream>
#include <string>

class Pracownik {
  std::string imie;

public:
  Pracownik(const std::string &i) : imie(i) {}
  virtual double pensja() const { return 0; }
  virtual void wypisz() const {
    std::cout << imie << ", pensja: " << pensja() << std::endl;
  }
  virtual ~Pracownik() {}
};

class Etatowy : public Pracownik {
  double stawka;

public:
  Etatowy(const std::string &i, double s) : Pracownik(i), stawka(s) {}
  double pensja() const override { return stawka; }
};

void przetworz(Pracownik &p) { p.wypisz(); }

int main() {
  Pracownik *tab[] = {new Etatowy("Ala", 5000)};
  przetworz(*tab[0]);
  delete tab[0];
}
