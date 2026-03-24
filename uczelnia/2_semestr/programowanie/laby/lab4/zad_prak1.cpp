#include <iostream>

static int g{0}; // inicjalizacja zerem
int main() {
  int n; // niezainicjalizowana zmienna - losowa wartość z pamięci
  std::cout << g << " " << n;
}
