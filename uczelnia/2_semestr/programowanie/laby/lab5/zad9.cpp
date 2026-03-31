// Napisz program, który:
// • pyta użytkownika o liczbę ocen n
// • dynamicznie alokuje tablicę n liczb double
// • wczytuje oceny od użytkownika
// • oblicza i wypisuje średnią, ocenę minimalną i maksymalną
// • wypisuje informację, czy student zaliczył (średnia >= 3.0)
// • poprawnie zwalnia pamięć
// Użyj funkcji pomocniczych: obliczSrednia(double* tab, int n), 
// znajdzMin(double* tab, int n), znajdzMax(double* tab, int n).

#include <iostream>

double obliczSrednia(double *tab, int n) {
  double sum = 0;
  for (int i = 0; i < n; i++) {
    sum += *(tab + i);
  }
  return sum / n;
}

double znajdzMin(double *tab, int n) {
  double min = 6, x;
  for (int i = 0; i < n; i++) {
    x = *(tab + i);
    min = x < min ? x : min;
  }
  return min;
}

double znajdzMax(double *tab, int n) {
  double max = 0, x;
  for (int i = 0; i < n; i++) {
    x = *(tab + i);
    max = x > max ? x : max;
  }
  return max;
}

int main() {
  std::cout << "Ile chcesz podać ocen: " << std::endl;
  int n;
  std::cin >> n;

  double *arr = new double[n];

  // wypełniamy tablicę
  for (int i = 0; i < n; i++) {
    std::cout << "Podaj ocenę numer " << i + 1 << ' ';
    std::cin >> *(arr + i);
  }
  double max = znajdzMax(arr, n);
  double min = znajdzMin(arr, n);
  double avg = obliczSrednia(arr, n);
  std::string comment = avg > 3.5 ? "Uczeń zaliczył :D" : "Uczeń oblał D:";
  std::cout << "=== Oceny ===" << std::endl;
  for (int i = 0; i < n; i++) {
    std::cout << *(arr + i) << ' ';
  }
  std::cout << std::endl;

  std::cout << "=== Informacje ===" << std::endl;
  std::cout << "Największa ocena: " << max << '\n' << "Najmniejsza ocena: " << min << '\n' << "Średnia: " << avg << '\n' << comment << std::endl;
  delete[] arr;
  arr = nullptr;

  return 0;
}
