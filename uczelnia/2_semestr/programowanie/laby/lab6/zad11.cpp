#include <stdio.h>
#include <string>

class Produkt {
public:
  std::string nazwa;
  float cena;
  Produkt(std::string nazwa, float cena) : nazwa(nazwa), cena(cena) {}
  Produkt() : nazwa(""), cena(0) {}

  const Produkt &operator=(const Produkt *p) {
    if (this != p) {
      nazwa = p->nazwa;
      cena = p->cena;
    }
    return *this;
  }
};

class Magazyn {
public:
  Produkt *produkty;
  size_t max_pojemnosc;
  size_t aktualna_pojemnosc;

  Magazyn(size_t pojemnosc) {
    this->max_pojemnosc = pojemnosc;
    this->aktualna_pojemnosc = 0;
    produkty = new Produkt[pojemnosc];
  }
  ~Magazyn() { delete[] produkty; }

  void dodaj(const Produkt &p) {
    if (aktualna_pojemnosc >= max_pojemnosc) {
      printf("Nie można dołożyć elementu, za mało miejsca\n");
      return;
    }

    produkty[aktualna_pojemnosc++] = p;
  }

  Produkt *znajdz(std::string nazwa) {
    for (size_t i = 0; i < aktualna_pojemnosc; i++) {
      if (produkty[i].nazwa == nazwa) {
        return &produkty[i];
      }
    }
    return nullptr;
  }

  void wypiszWszystkie() const {
    for (size_t i = 0; i < aktualna_pojemnosc; i++) {
      printf("Nazwa: %s | Cena: %0.2f\n", produkty[i].nazwa.c_str(),
             produkty[i].cena);
    }
  }
};

int main() {
  Magazyn m(5);
  m.dodaj(Produkt("Laptop", 3500.0));
  m.dodaj(Produkt("Mysz", 49.99));
  m.dodaj(Produkt("Klawiatura", 129.0));
  Produkt *p = m.znajdz("Mysz");
  if (p != nullptr) {
    p->cena = 39.99; // zmiana przez wskaźnik
  }
  m.wypiszWszystkie();
}
