// Napisz funkcję o poniższej sygnaturze. Zaalokuj tablicę, wypełnij ją kole
// nymi wielokrotnościami
// wartości krok i zwróć wskaźnik. Pamiętaj, że wywołujący jest odpowiedzialny za  del
// te[].

#include <iostream>

int *generujTableau(int n, int krok) {
  int *arr = new int[n];
  for (int i = 0; i < n; i++) {
    *(arr + i) = krok * i;
  }
  return arr;
}

void pokazTableau(int *arr, int n) {
  for (int i = 0; i < n; i++) {
    std::cout << *(arr + i) << ' ';
  }
  std::cout << std::endl;
}

int main() {
  int *arr = generujTableau(5, 3);
  pokazTableau(arr, 5);
}

// Przykład: generujTableau(5, 3) zwraca {0, 3, 6, 9, 12}
