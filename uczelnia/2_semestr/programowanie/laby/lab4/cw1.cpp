#include <iostream>

int main() {
  int a;
  int b = 5;
  int c(6);
  int d{7};
  int e{};
  std::cout << a << " " << b << " " << c << " " << d << " " << e << std::endl; // 0 5 6 7 0
}
