#include <iostream>

class Prostokat {
  double szer, wys;

public:
  Prostokat() : szer(0), wys(0) {}
  Prostokat(double a, double b) : szer(a), wys(b) {}
  void pokaz() const { std::cout << szer << "x" << wys << std::endl; }
};

int main() {
  Prostokat p1;
  Prostokat p2(2, 3); // wywołuje konstruktor
  Prostokat p3{4, 5}; // przypisuje w kolejności występowania zmiennych w ciele 
                      // funkcji, nie pozwala na rzutowanie
  p1.pokaz();
  p2.pokaz();
  p3.pokaz();
}
