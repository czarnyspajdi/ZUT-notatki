#include <algorithm>
#include <iostream>
#include <vector>

template <typename T> T wiekszy(T a, T b) { return a > b ? a : b; }

template <typename T> void zamien(T &a, T &b) {
  T c = a;
  a = b;
  b = c;
}

template <typename T> void wypisz(T *tab, int n) {
  for (int i = 0; i < n; i++) {
    std::cout << *(tab + i);
  }
  std::cout << std::endl;
}

template <typename T> void sortuj3(T a, T b, T c) {
  std::vector<T> vec{a, b, c};
  std::sort(vec.begin(), vec.end());

  for (const auto &symbol : vec) {
    std::cout << symbol;
  }
}
