#include <cmath>
#include <iostream>
#include <string>

class Ksztalt {
public:
  std::string kolor = "czerwony";

public:
  void opis() { std::cout << "Kolor tego kształtu to: " << kolor; }
};

class Kolo : public Ksztalt {
  float r = 3;
  float pole() { return M_PI * pow(r, 2); }
  friend std::ostream &operator<<(std::ostream &os, Kolo kolo) {
    os << "Koło o kolorze: " << kolo.kolor << " i promieniu " << kolo.r
       << " oraz polu " << kolo.pole();
    return os;
  }
};

class Prostokat : public Ksztalt {
  float a = 2, b = 4;
  float pole() { return a * b; }
  friend std::ostream &operator<<(std::ostream &os, Prostokat prostokat) {
    os << "Prostokąt o kolorze: " << prostokat.kolor
       << " i bokach dlugości a =  " << prostokat.a << ", b = " << prostokat.b
       << " i polu " << prostokat.pole();
    return os;
  }
};

int main() {
  Prostokat p = Prostokat();
  std::cout << p << std::endl;
  Kolo k = Kolo();
  std::cout << k << std::endl;
}
