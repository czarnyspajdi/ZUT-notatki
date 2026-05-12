#include <cmath>
#include <iostream>
#include <memory>
#include <vector>

class Figura {
public:
  virtual float pole() const = 0;
  virtual float obwod() const = 0;
  virtual ~Figura() = default;
};

class Kolo : public Figura {
  float r;

public:
  Kolo(float r) : r(r) {}

  float pole() const override { return M_PI * r * r; }
  float obwod() const override { return M_PI * 2 * r; }
};

class Prostokat : public Figura {
  float a, b;

public:
  Prostokat(float a, float b) : a(a), b(b) {}

  float pole() const override { return a * b; }
  float obwod() const override { return 2 * a + 2 * b; }
};

class Trojkat : public Figura {
  float a, b, c, h;

public:
  Trojkat(float a, float b, float c, float h) : a(a), b(b), c(c), h(h) {}

  float pole() const override { return (a * h) * 0.5; }
  float obwod() const override { return a + b + c; }
};

int main() {
  std::vector<std::unique_ptr<const Figura>> figury;
  figury.push_back(std::make_unique<Kolo>(2.0));
  figury.push_back(std::make_unique<Prostokat>(2, 3));
  figury.push_back(std::make_unique<Trojkat>(1, 2, 3, 4));

  for (std::unique_ptr<const Figura> &element : figury) {
    std::cout << "Obwod figury to: " << element->obwod() << std::endl;
    std::cout << "Pole figury to: " << element->pole() << std::endl;
    ;
  }
}
