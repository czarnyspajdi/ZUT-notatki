#include "licznik.cpp"
#include "wektor.cpp"

int main() {
  Wektor2D a(1, 2), b(3, 4);
  a += b;
  std::cout << a << std::endl; // (4,6)
  Licznik c(10);
  Licznik d = c++;
  std::cout << c << " " << d << std::endl; // 11 10
}
