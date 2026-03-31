// Poniższy kod zawiera kilka błędów. Wskaż każdy z nich i zaproponuj poprawkę

void funkcja() {
  int *a = new int(
      10); // do wskaźnika a przypisujemy wartość 10 zaalokowaną na stercie
  int *b = new int(
      20); // do wskaźnika b przypisujemy wartość 20 zaalokowaną na stercie
  // a = b;                // (1) // do wskaźnika a przypisujemy adres wskaźnika b
  // teraz oba wskaźniki wskazują na 20.

  // delete a;             // (2) // usuwa wartość 20 ze sterty
  // delete b;             // (3) // usuwa wartość 20 ze sterty

  // poprawa: zamiast przypisywać adresy przypiszmy wartości na które wskazują!
  *a = *b;
  delete a;
  delete b;
  // dodatkowo pokażmy że nie wskazują teraz na nic
  a = nullptr;
  b = nullptr;
}
