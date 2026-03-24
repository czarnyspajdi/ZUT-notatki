#include <iostream>
#include <vector>

int main() {
  std::vector<int> v1(5);          // vector 5 elementowy
  std::vector<int> v2{5};          // vector 1 elementowy
  std::vector<int> v3 = {1, 2, 3}; // vector 3 elementowy
  std::cout << v1.size() << " " << v2.size() << " " << v3.size() << std::endl;
}
