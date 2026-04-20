#include <stdexcept>
#include <stdio.h>

class Konto {
  float saldo;

public:
  Konto(int saldoPoczatkowe) : saldo(saldoPoczatkowe) {}
  void wplac(float pieniadze) { saldo += pieniadze; }
  void wyplac(float pieniadze) {
    if (saldo - pieniadze <= 0) {
      throw std::invalid_argument(
          "Saldo po wypłacie nie może być mniejsze niż 0!!!\n");
    }
    saldo -= pieniadze;
  }
  void pokazSaldo() { printf("Aktualne saldo to: %0.2f\n", saldo); }
};

int main() {
  float n = 200;
  printf("Tworzymy konto z saldem początkowym %0.2f\n", n);
  Konto k = Konto(n);
  k.pokazSaldo();

  printf("Wypłacamy 100 zł\n");
  k.wyplac(100);
  k.pokazSaldo();

  printf("Wpłacamy 50 zł\n");
  k.pokazSaldo();

  printf("Próbujemy wypłacić 6769 złoty\n");

  try {
    k.wyplac(6769);
  } catch (std::invalid_argument &ex) {
    printf("Nie wolno wypłacić aż tyle pieniędzy! %s", ex.what());
  }
}
