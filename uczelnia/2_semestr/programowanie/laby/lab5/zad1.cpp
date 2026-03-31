// Prześledź krok po kroku poniższy kod. Dla każdej linii zanotuj wartość ptr, *ptr 
// (jeśli dostępna) oraz czy pamięć jest zaalokowana.

#include <iostream>

int main() {
  int *ptr = nullptr; // deklarujemy wskaźnik wskazujący na nic
  ptr = new int(5);   // wskaźnik wskazuje teraz na wartość 5. jest ona za
                      // lokowana na stercie
  std::cout << *ptr << '\n'; // wyświetla 5
  *ptr = *ptr + 3;           // zwiększamy wartość o 3
  std::cout << *ptr << '\n'; // wyświetla 8
  delete ptr;                // usuwa liczbę na którą wskazuje wskaźnik
  ptr = nullptr;             // wskaźnik teraz na nic nie wskazuje
}
