#include <iostream>

template <typename T> T minZ3(T a, T b, T c) {
  return a < b ? (a < c ? a : c) : (b < c ? b : c);
}

int main() {
  if (minZ3(7, 2, 5) == 2) {
    std::cout << "1 ok\n";
  }
  if (minZ3(3.5, 1.2, 4.8) == 1.2) {
    std::cout << "2 ok\n";
  }
}
