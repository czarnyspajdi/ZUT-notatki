#include <iostream>
#include <ostream>

class Liczba {
  int wartosc;

public:
  Liczba(int w) : wartosc(w) {}
  Liczba operator+(Liczba &inny) {
    wartosc += inny.wartosc;
    return *this;
  }
  friend std::ostream &operator<<(std::ostream &os, const Liczba &liczba) {
    return os << liczba.wartosc;
  }
};

int main() {
  Liczba l1 = Liczba(5);
  Liczba l2 = Liczba(10);
  Liczba l3 = l1 + l2;
  std::cout << l3;
  return 0;
}
