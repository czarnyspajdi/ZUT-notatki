#include <iostream>

class Baza {
public:
  void metoda() const { std::cout << "Baza" << std::endl; }
};

class Pochodna : public Baza {
public:
  void metoda() const { std::cout << "Pochodna" << std::endl; }
};

int main() {
  Pochodna p;
  Baza &ref = p;
  Baza *ptr = &p;
  p.metoda();    // pochodna
  ref.metoda();  // baza
  ptr->metoda(); // baza
}
