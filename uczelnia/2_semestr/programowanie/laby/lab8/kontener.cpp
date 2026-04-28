#include <iostream>
class Kontener {
  int *dane;
  int n;

public:
  Kontener(int rozmiar) : n(rozmiar), dane(new int[rozmiar]()) {}
  const int &operator[](int i) const { return dane[i]; }

  Kontener &operator+=(const Kontener &inny) {
    for (int i = 0; i < n; i++)
      dane[i] += inny.dane[i];
    return *this;
  }
  operator int() const { return n; }
};

int main() {
  Kontener k = Kontener(5);
  k += 1;
  std::cout << int(k);
}
