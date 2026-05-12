#include <iostream>
#include <ostream>
#include <string>

class Pojazd {
public:
  virtual std::string opis() = 0;
  virtual ~Pojazd() = default;

  friend std::ostream &operator<<(std::ostream &os, Pojazd &p) {
    os << p.opis();
    return os;
  }
};

class Samochod : public Pojazd {
public:
  std::string opis() override { return "To jest samochód"; }
};

class Rower : public Pojazd {
public:
  std::string opis() override { return "To jest rower"; }
};

int main() {
  Samochod s;
  Rower r;
  std::cout << s << std::endl;
  std::cout << r << std::endl;
}
