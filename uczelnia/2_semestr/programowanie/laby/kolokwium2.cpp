#include <cstddef>
#include <iostream>
#include <string>

class Towar {
  double cena;
  int sztuki;

public:
  std::string nazwa;
  Towar(std::string nazwa, double cena, int sztuki)
      : nazwa(nazwa), cena(cena), sztuki(sztuki) {}
  Towar() {}

  void wypisz() const {
    std::cout << "Nazwa: " << nazwa << '\n'
              << "Cena: " << cena << '\n'
              << "Liczba sztuk: " << sztuki << std::endl;
  }
  double wartosc() const { return cena * sztuki; }
  void zmienCene(double nowaCena) { cena = nowaCena; }
  void dodajSztuki(int ile) { sztuki += ile; }
  // int operator+(Towar &t) { return cena + t.cena; }
  Towar operator+(Towar &t) {
    return Towar(nazwa + t.nazwa, cena + t.cena, sztuki + t.sztuki);
  }
};

class Sklep {
  Towar *sklep;
  int max_ammount;
  int current_ammount;
  static int sklep_ammount;

public:
  Sklep(size_t max_towary)
      : max_ammount(max_towary), sklep(new Towar[max_towary]),
        current_ammount(0) {
    Sklep::sklep_ammount++;
  }

  ~Sklep() {
    delete[] sklep;
    sklep = nullptr;
    Sklep::sklep_ammount--;
  }

  bool dodajTowar(const Towar &t) {
    if (current_ammount >= max_ammount) {
      return false;
    }
    sklep[current_ammount++] = t;
    return true;
  }

  Towar *znajdzTowar(const std::string &nazwa) {
    for (int i = 0; i < current_ammount; i++) {
      if (sklep[i].nazwa == nazwa) {
        return &sklep[i];
      }
    }
    return nullptr;
  }

  void wypiszWszystkie() const {
    for (int i = 0; i < current_ammount; i++) {
      sklep[i].wypisz();
    }
  }

  double obliczWartoscSklepu() const {
    double sum = 0;
    for (int i = 0; i < current_ammount; i++) {
      sum += sklep[i].wartosc();
    }
    return sum;
  }

  static int ileSklepow() { return Sklep::sklep_ammount; }
};

int Sklep::sklep_ammount = 0;

int main() {
  Sklep sklep = Sklep(5);
  std::cout << "=== 1. Oryginalny stan sklepu ===" << std::endl;
  sklep.dodajTowar(Towar("Marchewka", 2, 3));
  sklep.dodajTowar(Towar("Banan", 4, 2));
  sklep.dodajTowar(Towar("Jabłko", 5, 3));
  sklep.dodajTowar(Towar("Ziemniak", 10, 15));
  sklep.wypiszWszystkie();

  std::cout << std::endl;
  std::cout << "=== 2. Modyfikowany stan sklepu ===" << std::endl;

  Towar *znalezionyTowar = sklep.znajdzTowar("Marchewka");
  znalezionyTowar->zmienCene(4);
  sklep.wypiszWszystkie();
  Towar *znalezionyTowar2 = sklep.znajdzTowar("Banan");

  std::cout << std::endl;
  std::cout << "=== 3. Dodajemy marchewkę z bananem ===" << std::endl;

  Towar suma_towarow = *znalezionyTowar + *znalezionyTowar2;
  suma_towarow.wypisz();

  std::cout << std::endl;
  std::cout << "=== 4. Wypisujemy wszystkie towary ===" << std::endl;

  sklep.wypiszWszystkie();

  std::cout << std::endl;
  std::cout << "=== 5. Wypisujemy łączną wartość sklepu ===" << std::endl;

  std::cout << "Wartość: " << sklep.obliczWartoscSklepu() << std::endl;

  std::cout << std::endl;
  std::cout << "=== 6. Wypisujemy łączną ilość sklepów ===" << std::endl;

  std::cout << "Ilość: " << sklep.ileSklepow() << std::endl;
}
