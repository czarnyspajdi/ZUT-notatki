// Poniższy fragment ma błąd logiczny i błąd zarządzania pamięcią. Zidentyfikuj oba i n
// apisz poprawną wersję.

int *stworzTablice(int n) {
  int tab[n]; // (1) — co jest nie tak?
  for (int i = 0; i < n; i++)
    tab[i] = i;
  return tab; // (2) — co jest nie tak?
}
