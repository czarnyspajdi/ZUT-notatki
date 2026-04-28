#include <iostream>
#include <ostream>
#define SIZE 2

class Macierz2x2 {

public:
  int macierz[SIZE][SIZE];
  Macierz2x2(int a, int b, int c, int d) {
    macierz[0][0] = a;
    macierz[0][1] = b;
    macierz[1][0] = c;
    macierz[1][1] = d;
  }
  Macierz2x2() {
    for (int i = 0; i < SIZE; i++) {
      for (int j = 0; j < SIZE; j++) {
        macierz[i][j] = 0;
      }
    }
  }

  Macierz2x2 &operator+=(const Macierz2x2 &inna_macierz) {
    for (int i = 0; i < SIZE; i++) {
      for (int j = 0; j < SIZE; j++) {
        macierz[i][j] += inna_macierz.macierz[i][j];
      }
    }
    return *this;
  }

  Macierz2x2 operator+(const Macierz2x2 &inna_macierz) const {
    Macierz2x2 m = *this;
    m += inna_macierz;
    return m;
  }

  Macierz2x2 &operator-=(const Macierz2x2 &inna_macierz) {
    for (int i = 0; i < SIZE; i++) {
      for (int j = 0; j < SIZE; j++) {
        macierz[i][j] -= inna_macierz.macierz[i][j];
      }
    }
    return *this;
  }

  Macierz2x2 operator-(const Macierz2x2 &inna_macierz) const {
    Macierz2x2 m = *this;
    m -= inna_macierz;
    return m;
  }

  Macierz2x2 operator*(const Macierz2x2 &inna_macierz) const {
    Macierz2x2 m;
    m.macierz[0][0] = macierz[0][0] * inna_macierz.macierz[0][0] +
                      macierz[0][1] * inna_macierz.macierz[1][0];
    m.macierz[0][1] = macierz[0][0] * inna_macierz.macierz[0][1] +
                      macierz[0][1] * inna_macierz.macierz[1][1];
    m.macierz[1][0] = macierz[1][0] * inna_macierz.macierz[0][0] +
                      macierz[1][1] * inna_macierz.macierz[1][0];
    m.macierz[1][1] = macierz[1][0] * inna_macierz.macierz[0][1] +
                      macierz[1][1] * inna_macierz.macierz[1][1];
    return m;
  }

  int *operator[](int x) { return macierz[x]; }
  const int *operator[](int x) const { return macierz[x]; }

  friend std::ostream &operator<<(std::ostream &os, Macierz2x2 &macierz) {
    for (int i = 0; i < SIZE; i++) {
      os << '[';
      for (int j = 0; j < SIZE; j++) {
        os << macierz.macierz[i][j];
        if (j < SIZE - 1)
          os << " ";
      }
      os << ']';
      os << '\n';
    }
    return os;
  }

  friend std::istream &operator>>(std::istream &is, Macierz2x2 &macierz) {
    char separator;
    is >> macierz.macierz[0][0] >> separator >> macierz.macierz[0][1] >>
        separator >> macierz.macierz[1][0] >> separator >>
        macierz.macierz[1][1];
    return is;
  }

  explicit operator double() const {
    return macierz[0][0] * macierz[1][1] - macierz[1][0] * macierz[0][1];
  }

  const int operator()(int i, int j) const { return macierz[i][j]; }
  int &operator()(int i, int j) { return macierz[i][j]; }
};

int main() {
  Macierz2x2 m1 = Macierz2x2(1, 2, 3, 4);
  std::cout << "Macierz 1:\n";
  std::cout << m1;
  Macierz2x2 m2;
  std::cout << "Podaj swoją macierz: \n";
  std::cout << "Macierz 2:\n";
  std::cin >> m2;
  std::cout << m2;
  Macierz2x2 m3 = m1 + m2;
  Macierz2x2 m4 = m1 * m2;
  std::cout << "Macierz 3(dodawanie):\n";
  std::cout << m3 << std::endl;
  std::cout << "Macierz 4(mnożenie):\n";
  std::cout << m4 << std::endl;
  std::cout << "Wyznacznik macierz m1: " << double(m1) << std::endl;
  std::cout << "Element (1,1) macierzy m1: " << m1(1, 1) << std::endl;
  ;
}
