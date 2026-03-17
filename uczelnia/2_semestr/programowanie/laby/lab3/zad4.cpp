#include <iostream>

class Prostokat {
private:
  int a;
  int b;

public:
  Prostokat(int x, int y) : a(x), b(y) {}
};
Prostokat p1;
Prostokat p2(2, 3);
Prostokat p3{4, 5};

int main() {}
