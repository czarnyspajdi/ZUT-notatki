#include <iostream>
using namespace std;

int main() {
  struct Punkt {
    int x, y;
  };
  Punkt p1;
  Punkt p2{10, 20};
  Punkt p3 = {30, 40};

  cout << p1.x << ' ' << p1.y; // 0 0
  cout << endl;
  cout << p2.x << ' ' << p2.y; // 10 20
  cout << endl;
  cout << p3.x << ' ' << p3.y; // 30 40
}
