#include <cstddef>
#include <iostream>

class Zasob {
  int *arr;

public:
  Zasob(size_t size) : arr(new int[size]) { std::cout << "Alokujemy arr\n"; }

  virtual ~Zasob() { // bez tego – wyciek pamięci
    std::cout << "Destruktor virtualny\n";
    delete[] arr;
  }
};

class DuzyZasob : public Zasob {
  int *arr2;

public:
  DuzyZasob(size_t size1, size_t size2) : Zasob(size1), arr2(new int[size2]) {
    std::cout << "Alokujemy arr2\n";
  }
  ~DuzyZasob() override {
    std::cout << "Domyślny Destruktor DużegoZasobu\n";
    delete[] arr2;
  }
};

int main() {
  Zasob *z = new DuzyZasob(2, 4);
  delete z;
}
