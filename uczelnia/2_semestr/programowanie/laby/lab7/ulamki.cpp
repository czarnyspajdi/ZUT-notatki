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
};

Ulamek stworz_ulamek() {
  int licznik, mianownik;
  std::cout << "Podaj licznik: ";
  std::cin >> licznik;
  std::cout << "Podaj mianownik: ";
  std::cin >> mianownik;
  return Ulamek(licznik, mianownik);
}

int main() {
  Ulamek u1 = stworz_ulamek();
  std::cout << "Ulamek 1: " << u1 << std::endl;
  Ulamek u2 = stworz_ulamek();
  std::cout << "Ulamek 2: " << u2 << std::endl;
  std::cout << "=== OPERACJE ===" << std::endl;
  std::cout << "Dodawanie: " << u1 + u2 << std::endl;
  std::cout << "Odejmowanie: " << u1 - u2 << std::endl;
  std::cout << "Mnożenie: " << u1 * u2 << std::endl;
  try {
    std::cout << "Dzielenie: " << u1 / u2 << std::endl;
  } catch (const std::invalid_argument &e) {
    std::cout << "Błąd: " << e.what() << std::endl;
  }
  std::cout << "=== PORÓWNYWANIE ===" << std::endl;
  std::cout << std::boolalpha;
  std::cout << u1 << " == " << u2 << ": " << (u1 == u2) << std::endl;
  std::cout << u1 << " != " << u2 << ": " << (u1 != u2) << std::endl;
  std::cout << u1 << " <= " << u2 << ": " << (u1 <= u2) << std::endl;
  std::cout << u1 << " >= " << u2 << ": " << (u1 >= u2) << std::endl;
  std::cout << u1 << " < " << u2 << ": " << (u1 < u2) << std::endl;
  std::cout << u1 << " > " << u2 << ": " << (u1 > u2) << std::endl;
}
