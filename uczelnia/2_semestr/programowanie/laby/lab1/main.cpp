#include <iostream>
#include <string>

class Klasa {
public:
  std::string tekst;

  Klasa(std::string &str) {
    tekst = str;
    std::cout << "Tekst który podałeś przy tworzeniu klasy to: " << str <<
              std::endl;
  }

  void wyswietl_tekst() { std::cout << "Tekst to: " << tekst << std::endl; }
};

int main() {
  std::string tekst = "abc";
  Klasa k(tekst);
  k.wyswietl_tekst();
}
