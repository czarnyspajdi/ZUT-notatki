#include <iostream>

class Prostokat {
  double szer, wys;
  const double pole;

public:
  Prostokat(double a, double b) : szer(a), wys(b), pole(a * b) {
    std::cout << "Konstruktor zwykły" << std::endl;
  }
  Prostokat() : szer(0), wys(0), pole(0) {
    std::cout << "Konstruktor domyślny" << std::endl;
  }
  Prostokat(Prostokat &prostokat)
      : szer(prostokat.szer), wys(prostokat.szer), pole(prostokat.pole) {
    std::cout << "Konstruktor kopiujący" << std::endl;
  }
  Prostokat &operator=(const Prostokat &prostokat) {
    std::cout << "Konstruktor przypisujący";

    if (this != &prostokat) {
      szer = prostokat.szer;
      wys = prostokat.wys;
    }
    return *this;
  }
};

int main() {
  Prostokat a(2, 3);
  Prostokat b = a;
  Prostokat c;
  c = a;
}
