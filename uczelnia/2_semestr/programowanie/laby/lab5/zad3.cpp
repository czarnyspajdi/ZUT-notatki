// Napisz program, który wczytuje od użytkownika liczbę n, alokuje tablicę n lic
// b całkowitych na stercie, wczytuje n wartości, oblicza i wypisuje ich 
// sumę, a następnie poprawnie zwalnia pamięć.

#include <iostream>

int sumuj(int *arr, int n) {
  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += *(arr + i);
  }
  return sum;
}

int main() {
  int n;
  std::cout << "Podaj rozmiar tablicy: ";
  int *arr = new int[n];
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    std::cout << "Podaj wartość numer: " << i + 1 << ": ";
    std::cin >> *(arr + i);
  }

  std::cout << "Suma tych liczb to: " << sumuj(arr, n);
  delete[] arr;
  arr = nullptr;
  return 0;
}
