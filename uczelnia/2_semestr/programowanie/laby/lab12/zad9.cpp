#include "narzedzia.hpp"

int main() {
  std::cout << wiekszy(2, 4) << std::endl;
  std::cout << wiekszy(2.2, 4.3) << std::endl;
  std::cout << wiekszy("abc", "cdf") << std::endl;

  std::cout << "\n===\n";

  int x = 2, y = 4;
  zamien(x, y);
  std::cout << x << ',' << y;

  double i = 2.5, j = 3.5;
  zamien(i, j);
  std::cout << i << ',' << j;

  std::string a = "abc", b = "cde";
  zamien(a, b);
  std::cout << a << ',' << b;
}
