#include <iostream>
using namespace std;

void rysujLinie(char znak = '*', int ile = 5) {
  for (int i = 0; i < ile; i++) {
    cout << znak;
  }
}

int main() { 
    cout << "bez argumentów:" << endl; 
    rysujLinie();
    cout << endl << "z jednym argumentem: " << endl;
    rysujLinie('-');
    cout << endl << "z dwoma argumentami: " << endl;
    rysujLinie('+', 10);
}
