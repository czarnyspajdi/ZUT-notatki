#include <iostream>
#include <ostream>
#include <string>

class Adres {
  std::string ulica;
  std::string miasto;
  std::string kodPocztowy;

public:
  Adres(std::string ulica, std::string miasto, std::string kodPocztowy)
      : ulica(ulica), miasto(miasto), kodPocztowy(kodPocztowy) {}
  friend std::ostream &operator<<(std::ostream &os, Adres adres) {
    os << adres.ulica << '\n' << adres.miasto << '\n' << adres.kodPocztowy;
    return os;
  }
};

class Osoba {
  Adres adres;

public:
  Osoba(Adres adres) : adres(adres) {}
  friend std::ostream &operator<<(std::ostream &os, Osoba osoba) {
    os << osoba.adres;
    return os;
  }
};

int main() {
  Osoba osoba = Osoba(Adres("żołnierska", "szczecin", "23-123")); 
  std::cout << osoba;
}
