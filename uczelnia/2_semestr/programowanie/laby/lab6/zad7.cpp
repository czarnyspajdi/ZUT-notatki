#include <iostream>

class Punkt {
public:
  int x, y;
  Punkt(int x, int y) : x(x), y(y) {}

  void wyswietl() { std::cout << '(' << x << ',' << y << ')' << std::endl; }
};

void zamienRef(Punkt &a, Punkt &b) {
  int x = a.x;
  int y = a.y;
  int i = b.x;
  int j = b.y;
  a.x = i;
  a.y = j;
  b.x = x;
  b.y = y;
}

void zamienWsk(Punkt *a, Punkt *b) {
  int x = a->x;
  int y = a->y;
  int i = b->x;
  int j = b->y;
  a->x = i;
  a->y = j;
  b->x = x;
  b->y = y;
}

int main() {
  std::cout << "Punkty: " << std::endl;
  Punkt p1(1, 2), p2(3, 4);
  p1.wyswietl();
  p2.wyswietl();
  std::cout << "Zamiana referencją: " << std::endl;
  zamienRef(p1, p2); // wywołanie przez referencję
                     //
  p1.wyswietl();
  p2.wyswietl();

  std::cout << "Zamiana wskaźnikiem: " << std::endl;
  zamienWsk(&p1, &p2); // wywołanie przez wskaźnik
  p1.wyswietl();
  p2.wyswietl();
}
