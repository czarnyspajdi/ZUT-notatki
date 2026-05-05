#include <iostream>
#include <string>

class Konto {
  float saldo = 2000;

protected:
  std::string numerKonta;
  float getSaldo() { return saldo; }
};

class KontoOszczednosciowe : public Konto {
  int oprocentowanie = 12;

public:
  // float naliczOdsetki() {
  //     return oprocentowanie * saldo;  // nie możemy tego wykonać, ponieważ 
  //     saldo jest polem prywatnym
  // }

  float naliczOdsetki() { return oprocentowanie * getSaldo(); }
};

int main() {
  KontoOszczednosciowe k = KontoOszczednosciowe();
  std::cout << k.naliczOdsetki();
}
