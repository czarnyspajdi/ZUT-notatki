#include <iostream>

class Zwierze {
public:
  virtual void odglos() { std::cout << "..." << std::endl; }
  virtual ~Zwierze() = default;
};

class Pies : public Zwierze {
public:
  void odglos() override { std::cout << "Hau hau" << std::endl; }
};

class Kot : public Zwierze {
public:
  void odglos() override { std::cout << "Miau miau" << std::endl; }
};

class Krowa : public Zwierze {
public:
  void odglos() override { std::cout << "Muu muu" << std::endl; }
};

int main() {
  const int SIZE = 3;
  Zwierze *zwierzeta[SIZE];
  zwierzeta[0] = new Pies();
  zwierzeta[1] = new Kot();
  zwierzeta[2] = new Krowa();

  for (int i = 0; i < SIZE; i++) {
    zwierzeta[i]->odglos();
  }

  for (int i = 0; i < SIZE; i++) {
    delete zwierzeta[i];
  }

  return 0;
}
