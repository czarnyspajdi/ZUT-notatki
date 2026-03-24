#include <iostream>
#include <vector>

struct Licznik {
  std::vector<int> dane;
  Licznik(std::initializer_list<int> il) : dane(il) {}
  void wyswietl() const {
    for (int x : dane)
      std::cout << x << " ";
    std::cout << "\n";
  }
};

int main() {
  Licznik l1{1, 2, 3};
  Licznik l2 = {4, 5, 6};
  // Licznik l3(7, 8, 9);
  l1.wyswietl(); // 1 2 3
  l2.wyswietl(); // 4 5 6
}
