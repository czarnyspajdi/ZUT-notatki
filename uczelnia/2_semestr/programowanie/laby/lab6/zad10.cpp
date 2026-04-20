#include <stdexcept>
#include <stdio.h>

class Konto {
  static int liczbaKont;
  float saldo;

public:
  Konto(int saldoPoczatkowe) : saldo(saldoPoczatkowe) { Konto::liczbaKont++; }
  void wplac(float pieniadze) { saldo += pieniadze; }
  void wyplac(float pieniadze) {
    if (saldo - pieniadze <= 0) {
      throw std::invalid_argument(
          "Saldo po wypłacie nie może być mniejsze niż 0!!!\n");
    }
    saldo -= pieniadze;
  }
  void pokazSaldo() { printf("Aktualne saldo to: %0.2f\n", saldo); }

  static void ileKont() {
    printf("Aktualnie jest %d kont\n", Konto::liczbaKont);
  }
};

int Konto::liczbaKont = 0;

int main() {
  Konto::ileKont();
  Konto k1 = Konto(20);
  Konto::ileKont();
  Konto k2 = Konto(20);
  Konto::ileKont();
  Konto k3 = Konto(20);
  Konto::ileKont();
}
