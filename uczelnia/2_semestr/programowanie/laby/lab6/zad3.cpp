#include <iostream>

class Licznik {
  int wartosc;

public:
  Licznik() : wartosc(0) {}
  void dodaj() { wartosc++; }
  int ile() const { return wartosc; }
};
int main() {
  Licznik a; // 0
  Licznik b; // 0
  a.dodaj(); // 1
  a.dodaj(); // 2
  a.dodaj(); // 3
  b.dodaj(); // 1
  std::cout << a.ile() << " " << b.ile()
            << "\n"; // a.ile() == 2 && b.ile() == 1
}
