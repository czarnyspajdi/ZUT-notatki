#include <iostream>

template <typename T> T potroj(T x) { return x * 3; }

int main() {
  std::cout << potroj(7) << '\n';   // 21
  std::cout << potroj(2.5) << '\n'; // 7.5
  std::cout << potroj('A') << '\n'; // dziwny znak
}
