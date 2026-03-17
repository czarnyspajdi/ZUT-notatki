#include <iostream>
#include <string>

class KontoBankowe {
  std::string wlasciciel;
  float saldo;

public:
  KontoBankowe(std::string wlasciciel, float saldo = 0.0)
      : wlasciciel(wlasciciel), saldo(saldo) {}
  ~KontoBankowe() { std::cout << "Zamykam konto bankowe" << std::endl; }

  void wplata(float pieniadze) { saldo += pieniadze; }
  void wyplata(float pieniadze) { saldo -= pieniadze; }
  void pokaz() { std::cout << wlasciciel << " ma " << saldo << " zł."; }
};

int main() {
  KontoBankowe konto("bogdan");
  konto.pokaz();
  konto.wplata(23.3);
  konto.pokaz();
  konto.wyplata(2);
  konto.pokaz();
}
