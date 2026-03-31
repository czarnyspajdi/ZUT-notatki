// Uzupełnij program i sprawdź zachowanie. Wyjaśnij, dlaczego wyniki mogą się różn
// ić.

#include <iostream>

void podwojWartoscia(int x) { x *= 2; }
void podwojWskaznikiem(int *p) { *p *= 2; }

int main() {
  int *q = new int(5);
  podwojWartoscia(*q);
  std::cout << *q << '\n'; // co zostanie wypisane? // 5
  podwojWskaznikiem(q);
  std::cout << *q << '\n'; // co zostanie wypisane? // 10
  delete q;
  // wyniki różnią się, bowiem w podwojeniu wartością mnożymy lokalną kopię argumentu razy 2, a w podwojeniu wskaźnikiem mnożymy wartość przetrzymywaną w miejscu, na które wskazuje wskaźnik
}
