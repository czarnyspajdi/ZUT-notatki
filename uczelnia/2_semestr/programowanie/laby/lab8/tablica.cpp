#include <cstddef>
#include <iostream>
#include <stdexcept>
#include <string>

class Tablica {
  int *arr;

  void is_size_correct(size_t index) const {
    if (index > size) {
      throw std::out_of_range("Zbyt duży index! Maksymalny rozmiar to %d" + 
                              std::to_string(size));
    }

    if (index < 0) {
      throw std::out_of_range("Zbyt mały index! Minimalny rozmiar to 0");
    }
  }

public:
  size_t size;

  Tablica(size_t size) : size{size} { arr = new int[size]; }

  // po zakomentowaniu tej metody program wciąż się kompiluje
  int &operator[](size_t index) const {
    is_size_correct(index);
    return *(arr + index);
  }

  int &operator[](size_t index) {
    is_size_correct(index);
    return *(arr + index);
  }
};

void przeczytaj_tablice(Tablica &tablica) {
  for (int i = 0; i < tablica.size; i++) {
    try {
      std::cout << tablica[i] << '\n';
    } catch (const std::out_of_range &e) {
      std::cout << e.what();
      continue;
    }
  }
}

int main() {
  Tablica t = Tablica(10);
  przeczytaj_tablice(t);
}
