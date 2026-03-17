#include <iostream>

class Test {
public:
  Test() { std::cout << "Konstruktor" << std::endl; }
  ~Test() { std::cout << "Destruktor" << std::endl; }
};

int main() {
  std::cout << "Start" << std::endl;
  Test a; // konstruktor 1
  {
    Test b; // konstruktor 2
    std::cout << "Wewnatrz bloku" << std::endl;
  } // destruktor 2
  std::cout << "Koniec" << std::endl;
  // destruktor 1
}
