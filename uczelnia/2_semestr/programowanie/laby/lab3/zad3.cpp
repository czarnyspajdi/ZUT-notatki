#include <iostream>

class Punkt {
  int x, y;

public:
  Punkt() {
    x = 0;
    y = 0;
  }

  Punkt(int x, int y) {
    this->x = x;
    this->y = y;
  }

  void pokaz() { std::cout << '(' << x << ',' << y << ')' << std::endl; }
};

int main() {
  int x, y;
  std::cout << "Podaj x i y: ";
  std::cin >> x;
  std::cin >> y;
  Punkt p;
  std::cout << "Domyślny punkt: ";
  p.pokaz();
  std::cout << std::endl;
  std::cout << "Punkt z twoimi danymi: ";
  Punkt p2(x, y);
  p2.pokaz();
}
