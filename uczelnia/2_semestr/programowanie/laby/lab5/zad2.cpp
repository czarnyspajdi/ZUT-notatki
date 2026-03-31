// Poniższy kod zawiera kilka błędów. Wskaż każdy z nich i zaproponuj poprawkę

void funkcja() {
  int *a = new int(10);
  int *b = new int(20);
  a = b;    // (1)
  delete a; // (2)
  delete b; // (3)
}
