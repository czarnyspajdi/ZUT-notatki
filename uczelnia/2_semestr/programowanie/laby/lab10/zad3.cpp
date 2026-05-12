#include <iostream>

class Baza {
public:
  virtual void metoda() const { std::cout << "Baza" << std::endl; }
};

class Pochodna : public Baza {
public:
  void metoda() const { std::cout << "Pochodna" << std::endl; }
};

int main() {
  Pochodna p;
  Baza b = p;
  b.metoda(); // część pochodna została zgubiona
}
