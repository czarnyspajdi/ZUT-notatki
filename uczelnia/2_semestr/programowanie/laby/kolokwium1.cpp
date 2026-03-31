#include <iostream>
using namespace std;

class Pole_Szymon_Prusiewicz {
public:
  int x, y;
  Pole_Szymon_Prusiewicz(int x, int y) : x(x), y(y) {
    cout << x << ' ' << y << endl;
  }
  ~Pole_Szymon_Prusiewicz() { cout << "koniec zycia" << endl; }
  void oblicz_pole() { cout << "Pole wynosi: " << x * y << endl; }

  Pole_Szymon_Prusiewicz &operator=(const Pole_Szymon_Prusiewicz &inne_pole) {
    cout << "Przypisanie" << endl;
    if (this != &inne_pole) {
      x = inne_pole.x;
      y = inne_pole.y;
    }

    return *this;
  }
};

int main() {
  Pole_Szymon_Prusiewicz p1(1, 2);
  Pole_Szymon_Prusiewicz p2 = p1;
  p1.oblicz_pole();
  return 0;
}
