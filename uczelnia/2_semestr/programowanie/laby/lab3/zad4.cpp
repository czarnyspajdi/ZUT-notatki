class Prostokat {
private:
  int a;
  int b;

public:
  Prostokat() {} // dodany pusty konstruktor, by kod się skompilował
  Prostokat(int x, int y) : a(x), b(y) {}
};

Prostokat p1; // w aktualnej formie się nie skompiluje, ponieważ nie istnieje 
              // konstruktor bezargumentowy
Prostokat p2(2, 3);
Prostokat p3{4, 5};

int main() {}
