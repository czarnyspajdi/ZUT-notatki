#include <iostream>

class Ksztalt {
public:
  virtual double pole() const = 0;
  virtual ~Ksztalt() = default;
};

class Kolo : public Ksztalt {
  double r;

public:
  Kolo(double promien) : r(promien) {}
  double pole() const { return 3.14 * r * r; }
};

void wypisz(Ksztalt &k) { std::cout << k.pole(); }

int main() {
  Kolo k = Kolo(2);
  wypisz(k);
}
