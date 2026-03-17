#include <iostream>
#include <string>

class Ksiazka {
  std::string tytul, autor;
  int rokWydania;

public:
  Ksiazka() {}

  Ksiazka(std::string tytul, std::string autor, int rokWydania)
      : tytul(tytul), autor(autor), rokWydania(rokWydania) {}
  ~Ksiazka() {
      std::cout << "Likwiduję książkę..." << std::endl;
  }

  void pokaz() {
    std::cout << "Ksiażka " << tytul << " została napisana przez " << autor << " w " << rokWydania << " roku." << std::endl;
  }
};

int main() {
    Ksiazka pusta_ksiazka;
    pusta_ksiazka.pokaz();
    Ksiazka niepusta_ksiazka("Ksiazka", "Stefan", 2026);
    niepusta_ksiazka.pokaz();
}


