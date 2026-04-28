#include <ios>
#include <iostream>
#include <numeric>
#include <stdexcept>

class Ulamek {
  void skroc() {
    int skracacz = std::gcd(licznik, mianownik);
    if (mianownik < 0) {
      licznik = -licznik;
      mianownik = -mianownik;
    }
    licznik /= skracacz;
    mianownik /= skracacz;
  }

public:
  int licznik, mianownik;

  Ulamek(int licznik, int mianownik) : licznik(licznik), mianownik(mianownik) {
    if (mianownik == 0) {
      throw std::invalid_argument("Mianownik nie moze byc zerem");
    }
    skroc();
  }

  Ulamek() : licznik(0), mianownik(1) {}

  explicit operator double() const {
    return static_cast<double>(licznik) / mianownik;
  }

  Ulamek operator+(const Ulamek &inny_ulamek) const {
    return Ulamek(licznik * inny_ulamek.mianownik +
                      inny_ulamek.licznik * mianownik,
                  mianownik * inny_ulamek.mianownik);
  }

  Ulamek operator-(const Ulamek &inny_ulamek) const {
    return Ulamek(licznik * inny_ulamek.mianownik -
                      inny_ulamek.licznik * mianownik,
                  mianownik * inny_ulamek.mianownik);
  }

  Ulamek operator*(const Ulamek &inny_ulamek) const {
    return Ulamek(licznik * inny_ulamek.licznik,
                  mianownik * inny_ulamek.mianownik);
  }

  Ulamek operator/(const Ulamek &inny_ulamek) const {
    if (inny_ulamek.licznik == 0) {
      throw std::invalid_argument("Dzielenie przez zero");
    }
    return Ulamek(licznik * inny_ulamek.mianownik,
                  mianownik * inny_ulamek.licznik);
  }

  bool operator==(const Ulamek &inny_ulamek) const {
    return licznik == inny_ulamek.licznik && mianownik == inny_ulamek.mianownik;
  }

  bool operator!=(const Ulamek &inny_ulamek) const {
    return !(*this == inny_ulamek);
  }

  bool operator<(const Ulamek &inny_ulamek) const {
    return licznik * inny_ulamek.mianownik < inny_ulamek.licznik * mianownik;
  }

  bool operator>=(const Ulamek &inny_ulamek) const {
    return !(*this < inny_ulamek);
  }

  bool operator<=(const Ulamek &inny_ulamek) const {
    return *this == inny_ulamek || *this < inny_ulamek;
  }

  bool operator>(const Ulamek &inny_ulamek) const {
    return !(*this <= inny_ulamek);
  }

  friend std::ostream &operator<<(std::ostream &os, const Ulamek &u) {
    os << u.licznik << '/' << u.mianownik;
    return os;
  }
  friend std::istream &operator>>(std::istream &is, Ulamek &u) {
    char separator;
    int licznik, mianownik;
    is >> licznik >> separator >> mianownik;

    if (mianownik == 0) {
      is.setstate(std::ios::failbit); // nadmiarowe, bo w konstruktorze też 
                                      // sprawdzamy czy mianownik == 0
    }

    if (is) {
      u = Ulamek(licznik, mianownik);
    }
    return is;
  }
};

int main() {
  Ulamek ulamek;
  std::cin >> ulamek;
  // double ulamek_double = ulamek; ta linia się nie skompiluje, ponieważ k
  // onwersja musi być explicit
  double ulamek_double = double(ulamek);
  std::cout << ulamek_double;
}
