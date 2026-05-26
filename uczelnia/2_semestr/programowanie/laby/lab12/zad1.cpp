#include <iostream>

template <typename T> T potroj(T x) { return x * 3; }

int main() {
  std::cout << potroj(7) << '\n';
  std::cout << potroj(2.5) << '\n';
  std::cout << potroj('A') << '\n';
}
