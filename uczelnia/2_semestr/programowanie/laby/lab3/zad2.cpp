#include <iostream>

class Punkt {
  int x, y;

public:
  void ustaw(int x, int y) {
    this->x = x;
    this->y = y;
  }

  void pokaz() { std::cout << '(' << x << ',' << y << ')' << std::endl; }

  ~Punkt() { std::cout << "Niscze punkt" << std::endl; }
};

int main() {
  int x, y;
  std::cout << "Podaj x i y: ";
  std::cin >> x;
  std::cin >> y;
  Punkt p;
  p.ustaw(x, y);
  p.pokaz();
}
