#include <iostream>

using namespace std;

void podwoj1(int x) { x *= 2; }
void podwoj2(int &x) { x *= 2; }

int main() {
  int a = 5;
  cout << a << endl;
  podwoj1(a); // nie zmieni wartości poza funkcją
  cout << "a po podwojeniu kopią: " << a << endl;
  podwoj2(a); // zmieni wartość poza funkcją
  cout << "a po podwojeniu referencją: " << a << endl;
}
