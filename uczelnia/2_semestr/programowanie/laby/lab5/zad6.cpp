// Poniższy fragment ma błąd logiczny i błąd zarządzania pamięcią. Zidentyfikuj oba i n
// apisz poprawną wersję.

int *stworzTablice(int n) {
  // int tab[n]; // (1) — co jest nie tak? // alokuje na stosie - błąd
  int *tab = new int[n]; // alokujemy na stercie
  for (int i = 0; i < n; i++)
    tab[i] = i;
  return tab; // (2) — co jest nie tak? // poprzednio zwracaliśmy adres lokalnej zm
              // ennej, teraz zwracamy adres danych zaalokowanych na stercie
              // i jest super
}

int main() { return 0; }
