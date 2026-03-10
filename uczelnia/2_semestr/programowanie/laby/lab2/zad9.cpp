#include <iostream>
using namespace std;

double srednia(int a, int b, int c) { return (double)(a + b + c) / 3; }

double srednia(int a, int b) { return (double)(a + b) / 2; }

double srednia(int a, int b, int c, int d) {
  return (double)(a + b + c + d) / 4;
}

bool czyZaliczyl(double wynik, double prog = 3.0) { return wynik >= prog; }

int main() {
  int a, b, c;
  cout << "Podaj a: ";
  cin >> a;
  cout << "Podaj b: ";
  cin >> b;
  cout << "Podaj c: ";
  cin >> c;

  double avg = srednia(a, b, c);
  cout << "Twoja średnia wynosi: " << avg << endl;
  if (czyZaliczyl(avg)) {
    cout << "Zaliczyłeś, brawo!" << endl;
  } else {
    cout << "Nie zaliczyłeś :(" << endl;
  }
}
