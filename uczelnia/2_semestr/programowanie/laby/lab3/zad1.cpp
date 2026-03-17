#include <iostream>

class Student {
private:
  std::string imie; // pole prywatne
  int nrAlbumu;     // pole prywatne

public:
  Student(std::string imie, int nrAlbumu) // konstruktor
      : imie(imie), nrAlbumu(nrAlbumu) {}
  void pokaz() { // publiczna metoda
    std::cout << imie << " " << nrAlbumu << std::endl;
  }
};
