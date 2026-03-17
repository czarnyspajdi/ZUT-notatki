#include <iostream>
#include <string>

class Produkt {
  std::string nazwa;
  float cena;

public:
  void ustawNazwe(std::string nazwa) { this->nazwa = nazwa; }
  void ustawCene(float cena) { this->cena = cena; }
  void pokaz() {
    std::cout << "Produkt " << nazwa << " kosztuje " << cena << " zł."; 
  }
};

int main() {
  Produkt p;
  p.ustawNazwe("Marchewka");
  p.ustawCene(234.342);
  p.pokaz();
}
