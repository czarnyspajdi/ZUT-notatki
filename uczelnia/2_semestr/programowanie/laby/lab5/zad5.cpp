// Uzupełnij program i sprawdź zachowanie. Wyjaśnij, dlaczego wyniki mogą się różn
// ić.

void podwojWartoscia(int x) { x *= 2; }
void podwojWskaznikiem(int *p) { *p *= 2; }
int *q = new int(5);
podwojWartoscia(*q);
std::cout << *q << '\n'; // co zostanie wypisane?
podwojWskaznikiem(q);
std::cout << *q << '\n'; // co zostanie wypisane?
delete q;
