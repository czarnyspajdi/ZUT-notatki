#include <iostream>

class Punkt2d {

public:
  double x, y;
  Punkt2d(double x, double y) : x(x), y(y) {}
  Punkt2d() : x(0), y(0) {}

  Punkt2d operator+(const Punkt2d &inny_pkt) const {
    Punkt2d pkt;
    pkt.x = x + inny_pkt.x;
    pkt.y = y + inny_pkt.y;
    return pkt;
  }

  Punkt2d operator-(const Punkt2d &inny_pkt) const {
    Punkt2d pkt;
    pkt.x = x - inny_pkt.x;
    pkt.y = y - inny_pkt.y;
    return pkt;
  }
  bool operator==(const Punkt2d &inny_pkt) const {
    if (x != inny_pkt.x || y != inny_pkt.y) {
      return false;
    }
    return true;
  }
  bool operator!=(const Punkt2d &inny_pkt) const {
    return !(*this == inny_pkt);
  }

  friend std::ostream &operator<<(std::ostream &os, const Punkt2d &inny_pkt) {
    os << '(' << inny_pkt.x << ',' << inny_pkt.y << ')';
    return os;
  }
};

int main() {
  Punkt2d a(6, 7), b(3, 4);
  Punkt2d c = a + b;
  std::cout << c << std::endl; // (9, 11)
  std::cout << (a == b) << std::endl; // false
  std::cout << (a != a) << std::endl; // false
}
