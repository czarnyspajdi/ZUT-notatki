#include <stdio.h>

class Prostokat {
public:
  double szerokosc;
  double wysokosc;
  double pole() { return szerokosc * wysokosc; }
  double obwod() { return 2 * szerokosc + 2 * wysokosc; }
};

int main() {
  Prostokat p1;
  p1.szerokosc = 2;
  p1.wysokosc = 2;
  double pole = p1.pole();
  double obwod = p1.obwod();
  printf(
      "Pole o szerokości %0.2f i wysokości %0.2f ma pole %0.2f i obwód %0.2f", 
      p1.szerokosc, p1.wysokosc, pole, obwod);
}
