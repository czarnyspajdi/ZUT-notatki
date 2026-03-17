#include <iostream>

class Student {
private:
  std::string imie; // pole prywatne
  int nrAlbumu;     // pole prywatne

public:
  Student(std::string imie, int nrAlbumu)
      : imie(imie), nrAlbumu(nrAlbumu) {} // konstruktor
  void pokaz() {                          // publiczna metoda
    std::cout << imie << " " << nrAlbumu << std::endl;
  }
};
