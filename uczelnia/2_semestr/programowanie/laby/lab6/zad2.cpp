class Prostokat {
private:
  double szerokosc;
  double wysokosc;

public:
  Prostokat(double szerokosc, double wysokosc)
      : szerokosc(szerokosc), wysokosc(wysokosc) {}
  double pole() { return szerokosc * wysokosc; }
  double obwod() { return 2 * szerokosc + 2 * wysokosc; }
  double getSzerokosc() { return szerokosc; }
  double getWysokosc() { return wysokosc; }
};

int main() {
  Prostokat p1 = Prostokat(2, 2);
  // p1.szerokosc = 4; taka operacja jest nieakceptowalna albowiem skrajnie
  // nierozsądnym i można powiedzieć __nieakceptowalnym__ jest próba przypisania 
  // wartości do pola oznaczonego mianem prywatnego. Na szczęście jaśnie 
  // oświecony kompilator języka c++ powstrzymuje nas przed takim godnym 
  // potępienia występkiem.
}
