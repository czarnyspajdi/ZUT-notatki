#include <iostream>

class Licznik {
  int wartosc;

public:
  Licznik(int w) : wartosc(w) {}
  void zwieksz() { wartosc++; }
  int pobierz() const { return wartosc; }
  void resetuj() { wartosc = 0; }
};
int main() {
  Licznik a(10);
  Licznik *wsk = &a;
  wsk->zwieksz();
  std::cout << a.pobierz() << '\n';    // 11 (linia A)
  std::cout << wsk->pobierz() << '\n'; // 11 (linia B)
  Licznik b(100);
  wsk = &b;
  wsk->zwieksz();
  std::cout << a.pobierz() << '\n'; // 11 (linia C)
  std::cout << b.pobierz() << '\n'; // 101 (linia D)
  a.resetuj();
  std::cout << a.pobierz(); // 0
}
