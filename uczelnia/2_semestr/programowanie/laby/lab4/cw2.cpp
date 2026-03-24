#include <iostream>

int main() {
  int t1[3] = {1, 2, 3};
  int t2[5] = {4, 5};

  for (int i = 0; i < 3; i++) {
    std::cout << t1[i] << std::endl; // 1 2 3
  }

  std::cout << std::endl;

  for (int i = 0; i < 5; i++) {
    std::cout << t2[i] << std::endl; // 4 5 0 0 0
  }
}
