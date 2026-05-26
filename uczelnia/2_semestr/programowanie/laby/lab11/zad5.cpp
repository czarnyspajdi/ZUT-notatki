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

class NiepolimorficznyTyp {};
class NiepolimorficznyTyp2 : public NiepolimorficznyTyp {};

void pokazTyp(const Pojazd *p) {
  const std::type_info &ti = typeid(*p);
  std::cout << "Rzeczywisty typ: " << ti.name() << std::endl;
}

void pokazTyp2(const NiepolimorficznyTyp *n) {
  const std::type_info &ti = typeid(*n);
  std::cout << "Rzeczywisty typ: " << ti.name() << std::endl;
}

int main() {
  Pojazd p;
  Samochod s;
  NiepolimorficznyTyp2 npol;
  pokazTyp(&p);
  pokazTyp(&s);
  pokazTyp2(&npol);
}
