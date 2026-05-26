#include <iostream>

template <typename T> void zamien(T &a, T &b) {
  T c = a;
  a = b;
  b = c;
}

template <typename T> void zamiana_i_wyswietlenie(T &x, T &y) {
  zamien(x, y); // teraz x == 2, y == 1
  std::cout << x << ',' << y << std::endl;
}

int main() {
  int x = 2, y = 4;
  zamiana_i_wyswietlenie(x, y);
  double i = 2.5, j = 3.5;
  zamiana_i_wyswietlenie(i, j);
  std::string a = "hej", b = "ho";
  zamiana_i_wyswietlenie(a, b);
}
