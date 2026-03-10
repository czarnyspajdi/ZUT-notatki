#include <iostream>
using namespace std;

double srednia(int a, int b, int c) { return (double)(a + b + c) / 3; }
void wyzeruj(int &x) { x = 0; }

int main() { 
    cout << "Średnia 2,2,3 to: " << srednia(2,2 , 3) << endl;
    int a = 6;
    cout << "a = " << a << endl;
    cout << "zerujemy" << endl;
    wyzeruj(a);
    cout << "a = " << a << endl;
}
