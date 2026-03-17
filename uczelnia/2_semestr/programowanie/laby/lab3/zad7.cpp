#include <iostream>

class Test {
public:
  Test() { std::cout << "Konstruktor" << std::endl; }
  ~Test() { std::cout << "Destruktor" << std::endl; }
};

int main() {
  std::cout << "Start" << std::endl;
  Test a;
  {
    Test b;
    std::cout << "Wewnatrz bloku" << std::endl;
  }
  std::cout << "Koniec" << std::endl;
}
