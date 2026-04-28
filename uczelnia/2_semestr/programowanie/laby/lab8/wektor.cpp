#include <iostream>

class Wektor2D {

public:
  double x, y;
  Wektor2D(double x, double y) : x(x), y(y) {}
  Wektor2D() : x(0), y(0) {}

  Wektor2D operator+=(const Wektor2D &inny_pkt) {
    this->x += inny_pkt.x;
    this->y += inny_pkt.y;
    return *this;
  }

  Wektor2D operator-=(const Wektor2D &inny_pkt) {
    this->x -= inny_pkt.x;
    this->y -= inny_pkt.y;
    return *this;
  }

  Wektor2D operator*=(const Wektor2D &inny_pkt) {
    this->x *= inny_pkt.x;
    this->y *= inny_pkt.y;
    return *this;
  }

  Wektor2D operator+(const Wektor2D &inny_pkt) const {
    Wektor2D p = *this;
    p += inny_pkt;
    return p;
  }

  Wektor2D operator-(const Wektor2D &inny_pkt) const {
    Wektor2D pkt;
    pkt.x = x - inny_pkt.x;
    pkt.y = y - inny_pkt.y;
    return pkt;
  }
  bool operator==(const Wektor2D &inny_pkt) const {
    if (x != inny_pkt.x || y != inny_pkt.y) {
      return false;
    }
    return true;
  }
  bool operator!=(const Wektor2D &inny_pkt) const {
    return !(*this == inny_pkt);
  }

  friend std::ostream &operator<<(std::ostream &os, const Wektor2D &inny_pkt) {
    os << '(' << inny_pkt.x << ',' << inny_pkt.y << ')';
    return os;
  }
};
