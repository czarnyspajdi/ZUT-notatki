#include <iostream>

class Bazowa {
protected:
  int x;

public:
  Bazowa(int x) : x(x) {}
};

class Pochodna : public Bazowa {
public:
  Pochodna(int val) : Bazowa(val) {}
  void wypisz() { std::cout << x << std::endl; }
};

int main() {
  Pochodna p = Pochodna(1);
  p.wypisz();
}
