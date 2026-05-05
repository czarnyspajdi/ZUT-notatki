#include <iostream>
class Wektor3d {
  int x, y, z;

public:
  Wektor3d(int x, int y, int z) : x(x), y(y), z(z) {}
  friend int iloczynSkalarny(const Wektor3d &w1, const Wektor3d &w2) {
    return w1.x * w2.x + w1.y * w2.y + w1.z * w2.z;
  }
};

int main() {
  Wektor3d w1(1, 2, 3);
  Wektor3d w2(3, 4, 5);
  std::cout << iloczynSkalarny(w1, w2);
}
