#include <iostream>
#include <ostream>

class Licznik {
  int wartosc;

public:
  Licznik(int wartosc) : wartosc(wartosc) {}
  Licznik() : wartosc(0) {}
  Licznik &operator++() {
    wartosc++;
    return *this;
  }
  Licznik operator++(int) {
    Licznik stary = *this;
    ++wartosc;
    return stary;
  }
  Licznik &operator--() {
    wartosc--;
    return *this;
  }
  Licznik operator--(int) {
    Licznik stary = *this;
    --wartosc;
    return stary;
  }
  Licznik &operator=(const Licznik &inny_licznik) {
    if (this != &inny_licznik) {
      wartosc = inny_licznik.wartosc;
    }
    return *this;
  }
  friend std::ostream &operator<<(std::ostream &os, Licznik &licznik) {
    os << licznik.wartosc;
    return os;
  }
};

// int main() {
//   Licznik a(5);
//   std::cout << a++ << std::endl; // 6
//   std::cout << a << std::endl;   // 6
//   std::cout << ++a << std::endl; // 7
// }
