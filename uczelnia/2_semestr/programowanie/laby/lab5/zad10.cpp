// Przepisz rozwiązanie zadania 9, używając std::unique_ptr<double[]> zamiast su
// rowego wskaźnika. Sprawdź, co musisz zmienić i co działa tak samo.

#include <iostream>
#include <memory>

double obliczSrednia(std::unique_ptr<double[]> &tab, int n) {
  double sum = 0;
  for (int i = 0; i < n; i++) {
    sum += tab[i];
  }
  return sum / n;
}

double znajdzMin(std::unique_ptr<double[]> &tab, int n) {
  double min = 6, x;
  for (int i = 0; i < n; i++) {
    x = tab[i];
    min = x < min ? x : min;
  }
  return min;
}

double znajdzMax(std::unique_ptr<double[]> &tab, int n) {
  double max = 0, x;
  for (int i = 0; i < n; i++) {
    x = tab[i];
    max = x > max ? x : max;
  }
  return max;
}

int main() {
  std::cout << "Ile chcesz podać ocen: " << std::endl;
  int n;
  std::cin >> n;

  std::unique_ptr<double[]> arr = std::make_unique<double[]>(n);

  // wypełniamy tablicę
  for (int i = 0; i < n; i++) {
    std::cout << "Podaj ocenę numer " << i + 1 << ' ';
    std::cin >> arr[i];
  }
  double max = znajdzMax(arr, n);
  double min = znajdzMin(arr, n);
  double avg = obliczSrednia(arr, n);
  std::string comment = avg > 3.5 ? "Uczeń zaliczył :D" : "Uczeń oblał D:";
  std::cout << "=== Oceny ===" << std::endl;
  for (int i = 0; i < n; i++) {
    std::cout << arr[i] << ' ';
  }
  std::cout << std::endl;

  std::cout << "=== Informacje ===" << std::endl;
  std::cout << "Największa ocena: " << max << '\n' << "Najmniejsza ocena: " << min << '\n' << "Średnia: " << avg << '\n' << comment << std::endl;

  return 0;
}
