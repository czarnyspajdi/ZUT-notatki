#include <iostream>
#include <memory>
#include <ostream>
#include <string>
#include <vector>

class Zwierze {
public:
  virtual std::string odglos() = 0;
  virtual std::string jedzenie() = 0;
  virtual double ileKalorii() = 0;
  virtual ~Zwierze() = default;

  friend std::ostream &operator<<(std::ostream &os, Zwierze &z) {
    os << "To zwierze wydaje dźwięk: " << z.odglos() << ".\nJe " << z.jedzenie()
       << " i potrzebuje " << z.ileKalorii() << " kalorii dziennie\n";
    return os;
  }
};

class Lew : public Zwierze {
public:
  std::string odglos() override { return "Odgłos lwa"; }
  std::string jedzenie() override { return "Mięso";}  
  double ileKalorii() override { return 2348; }
};

class Slon : public Zwierze {
public:
  std::string odglos() override { return "Odgłos słonia"; }
  std::string jedzenie() override { return "Liście";}  
  double ileKalorii() override { return 23; }
};

class Papuga : public Zwierze {
public:
  std::string odglos() override { return "Odgłos papugii"; }
  std::string jedzenie() override { return "Ziarna"; }
  double ileKalorii() override { return 2; }
};

class Waz : public Zwierze {
public:
  std::string odglos() override { return "Odgłos węża"; }
  std::string jedzenie() override { return "Mięso"; }
  double ileKalorii() override { return 387; }
};

class Opiekun {
public:
  void nakarm() { std::cout << "Nakarmione" << std::endl; }
};

class Wybieg {
  Opiekun opiekun_wybiegu;

public:
  std::vector<std::unique_ptr<Zwierze>> zwierzeta;

public:
  Wybieg(std::vector<std::unique_ptr<Zwierze>> zwierzeta,
         Opiekun opiekun_wybiegu)
      : zwierzeta(std::move(zwierzeta)), opiekun_wybiegu(opiekun_wybiegu) {}
};

class Zoo {
  std::vector<std::unique_ptr<Wybieg>> wybiegi;

public:
  Zoo(std::vector<std::unique_ptr<Wybieg>> wybiegi)
      : wybiegi(std::move(wybiegi)) {}

  double dziennaPorcjaKalorii() {
    double sum = 0;
    for (auto &wybieg : wybiegi) {
      for (const auto &zwierze : wybieg->zwierzeta) {
        sum += zwierze->ileKalorii();
      }
    }
    return sum;
  }

  friend std::ostream &operator<<(std::ostream &os, Zoo &z) {
    os << '[';
    for (auto &wybieg : z.wybiegi) {
      for (const auto &zwierze : wybieg->zwierzeta) {
        os << *zwierze << ',';
      }
    }
    os << ']';
    return os;
  }
};

int main() {
  std::vector<std::unique_ptr<Zwierze>> zwierzeta;
  zwierzeta.push_back(std::make_unique<Waz>());
  zwierzeta.push_back(std::make_unique<Slon>());
  zwierzeta.push_back(std::make_unique<Lew>());

  Opiekun opiekun;
  std::vector<std::unique_ptr<Wybieg>> wybiegi;

  wybiegi.push_back(std::make_unique<Wybieg>(std::move(zwierzeta), opiekun));

  Zoo zoo = Zoo(std::move(wybiegi));
  std::cout << "Dzienna porcja kalorii: " << zoo.dziennaPorcjaKalorii()
            << std::endl;

  std::cout << zoo;
}
