#include <iostream>
#include <memory>
#include <vector>

class Czlowiek {
public:
  virtual void mowa() const { std::cout << "..." << std::endl; }
  virtual ~Czlowiek() = default;
};

class Polak : public Czlowiek {
public:
  void mowa() const override { std::cout << "Czesc!" << std::endl; }
};

class Anglik : public Czlowiek {
public:
  void mowa() const override { std::cout << "Hello!" << std::endl; }
};

int main() {
  std::vector<std::unique_ptr<Czlowiek>> ludzie;
  ludzie.push_back(std::make_unique<Polak>());
  ludzie.push_back(std::make_unique<Anglik>());
  ludzie.push_back(std::make_unique<Czlowiek>());
  for (const auto &c : ludzie)
    c->mowa();
  // Cześć!
  // Hello!
  // ...

  // Przy metodzie niewirtualnej pojawi się błąd kompilacji – nadpisujemy meto
  // dę, która nie jest wirtualna
}
