#include <iostream>
#include <vector>
class Tablica {
  std::vector<int> tablica;

public:
  void dodaj(int x) { tablica.push_back(x); }

  void wypelnij(std::vector<int> &cel) {
    cel.insert(cel.end(), tablica.begin(), tablica.end());
  }

  int suma() const {
    int sum = 0;
    for (int element : tablica) {
      sum += element;
    }
    return sum;
  }

  void wyczysc() { tablica.clear(); }

  void wyswietl() {
    for (int element : tablica) {
      std::cout << element << ' ';
    }

    std::cout << std::endl;
  }
};

int main() {
  Tablica t;
  t.dodaj(3);
  t.wyswietl();
  t.dodaj(7);
  t.wyswietl();
  t.dodaj(1);
  t.wyswietl();
  std::vector<int> kopia;
  t.wypelnij(kopia);
  std::cout << "Kopia: " << std::endl;
  for (int element : kopia) {
    std::cout << element << ' ';
  }
  std::cout << std::endl;
  // kopia zawiera: 3, 7, 1
  int suma = t.suma();
  std::cout << "Suma wynosi: " << suma << std::endl;
  t.wyczysc();
  t.wyswietl();
}
