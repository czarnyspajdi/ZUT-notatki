// Przepisz poniższy kod, zastępując ręczną alokację obiektem unique_ptr.
// Upewnij się, że nie musisz pisać delete.

// Wersja z surowym wskaźnikiem:
// double *wynik = new double(3.14);
// std::cout << *wynik << '\n';
// delete wynik;
// Twoja wersja z unique_ptr:
// ...

#include <iostream>
#include <memory>

int main() {
  std::unique_ptr<double> wynik = std::make_unique<double>(3.14);
  std::cout << *wynik << '\n';
}
