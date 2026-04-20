#include <iostream>

class Kalkulator {
public:
  void podwoj(int x) { x *= 2; }
  void podwojRef(int &x) { x *= 2; }
  void zamien(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
  }
};
int main() {
  Kalkulator k;
  int a = 5, b = 10;
  k.podwoj(a); // a = 5
  std::cout << a << std::endl;
  k.podwojRef(a); // a = 10
  std::cout << a << std::endl;
  k.zamien(a, b); // a = 10, b = 10
  std::cout << a << ' ' << b << std::endl;
}
