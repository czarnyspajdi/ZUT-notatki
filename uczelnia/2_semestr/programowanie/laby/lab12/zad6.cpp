#include <iostream>

template <typename T> int policz(const T *tab, int n, T wartosc) {
  int count = 0;
  for (int i = 0; i < n; i++) {
    if (*(tab + i) == wartosc)
      count++;
  }
  return count;
}

int main() {
  int dane[] = {1, 2, 3, 2, 2, 5};
  if (policz(dane, 6, 2) == 3) {
    std::cout << "Zgadza się :D\n";
  }
}
