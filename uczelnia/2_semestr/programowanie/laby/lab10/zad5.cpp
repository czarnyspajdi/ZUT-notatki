#include <iostream>

class Abstrakcyjna {
public:
  virtual void f() = 0;
  virtual ~Abstrakcyjna() = default;
};

class Konkretna : public Abstrakcyjna {
public:
  void f() override { std::cout << "OK"; }
};

int main() {
  // Abstrakcyjna a;                      // nie kompiluje się, ponieważ a jest k
  // lasą abstrakcyjną.
  Konkretna k;                         // kompiluje
  Abstrakcyjna *ptr = new Konkretna(); // kompiluje
  Abstrakcyjna &ref = k;               // kompiluje
}
