#include <stdio.h>

class Pies {
public:
  static int liczba;
  Pies() { Pies::liczba++; }
};

int Pies::liczba = 0;

int main() {
  printf("Aktualnie jest %d psów\n", Pies::liczba); 
  Pies p1 = Pies();
  printf("Aktualnie jest %d psów\n", Pies::liczba); 
  Pies p2 = Pies();
  printf("Aktualnie jest %d psów\n", Pies::liczba); 
  Pies p3 = Pies();
  printf("Aktualnie jest %d psów\n", Pies::liczba); 
}
