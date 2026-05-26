#include <bitset>
#include <iostream>

template <typename T> class Liczalna {
public:
  void zliczDoN(int n) {
    for (int i = 0; i < n; i++) {
      static_cast<T *>(this)->wypisz(i);
    }
  }
};

class Dziesietna : public Liczalna<Dziesietna> {
public:
  void wypisz(int liczba) { std::cout << "Dziesietnie: " << liczba << "\n"; }
};

class Binarna : public Liczalna<Binarna> {
public:
  void wypisz(int liczba) {
    std::cout << "Binarnie: " << std::bitset<8>(liczba) << "\n";
  }
};

int main() {
  Dziesietna d;
  d.zliczDoN(4);

  Binarna b;
  b.zliczDoN(4);

  return 0;
}
