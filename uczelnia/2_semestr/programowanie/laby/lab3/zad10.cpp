#include <iostream>

class Punkt {
  int x, y;

public:
  Punkt(int x, int y) : x(x), y(y) {}
  Punkt() : Punkt(0, 0) {}
  void pokaz() { std::cout << '(' << x << ',' << y << ')' << std::endl; }
};

int main() {
  Punkt p;
  p.pokaz();
  Punkt p2(2, 2);
  p2.pokaz();
}
