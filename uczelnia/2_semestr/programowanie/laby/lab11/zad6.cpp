#include <iostream>
#include <typeinfo>

class Pojazd {
public:
  virtual ~Pojazd() = default;
  virtual void wydajDzwiekWirtualnie() {} // metoda wirtualna
};

class Samochod : public Pojazd {
public:
  void sygnal() { std::cout << "Sygnał!"; }
  void wydajDzwiekWirtualnie() override { std::cout << "Sygnał!"; }
};

class Rower : public Pojazd {
public:
  void Dzwonek() { std::cout << "Dzyń dzyń!"; }
  void wydajDzwiekWirtualnie() override { std::cout << "Dzyń dzyń!"; }
};

class Motocykl : public Pojazd {
public:
  void Warkot() { std::cout << "Wrum wrum!"; }
  void wydajDzwiekWirtualnie() override { std::cout << "Wrum wrum!"; }
};

int main() {
  Rower r;
  Pojazd *p = &r;

  Samochod *s_static = static_cast<Samochod *>(p);

  std::cout
      << "Wynik static_cast:  " << s_static
      << "\n"; // miejsce w pamięci. dowolne wywołanie metody zwróci teraz błąd

  Samochod *s_dynamic = dynamic_cast<Samochod *>(p);

  std::cout << "Wynik dynamic_cast: " << s_dynamic
            << "\n"; // nullptr, bo sprawdził w runtime, że typ się nie zgadza
}
