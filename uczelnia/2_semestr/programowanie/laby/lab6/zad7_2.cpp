#include <string>

class Samochod {
  std::string marka;
  int predkosc;

  Samochod(std::string marka, int predkosc) {
    this->marka = marka;
    this->predkosc = predkosc;
  }
};
