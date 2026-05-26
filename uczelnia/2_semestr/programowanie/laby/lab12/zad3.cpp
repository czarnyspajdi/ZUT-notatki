#include <iostream>

template <typename T> T srednia(T a, T b) { return (a + b) / 2; }

int main() {
  std::cout << srednia(3, 4) << std::endl;           // co się wypisze? 3
  std::cout << srednia(3.0, 4.0) << std::endl;       // co się wypisze? 3.5
  std::cout << srednia<double>(3, 4.0) << std::endl; // 3.5
}
