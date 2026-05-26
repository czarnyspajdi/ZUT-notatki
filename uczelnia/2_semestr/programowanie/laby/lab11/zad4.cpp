#include <iostream>

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

void wydajDzwiek(Pojazd *p) {
  if (Samochod *s = dynamic_cast<Samochod *>(p)) {
    s->sygnal();
  } else if (Rower *r = dynamic_cast<Rower *>(p)) {
    r->Dzwonek();
  } else if (Motocykl *m = dynamic_cast<Motocykl *>(p)) {
    m->Warkot();
  }
}

void wydajDzwiek2(Pojazd &p) { p.wydajDzwiekWirtualnie(); }

int main() {
  Rower r2;
  Pojazd *r = &r2;

  wydajDzwiek(r);
  wydajDzwiek2(r2);
}
