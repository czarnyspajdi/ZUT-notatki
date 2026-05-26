#include <iostream>
#include <memory>
#include <ostream>
#include <string>
#include <vector>

class StrategiaZywienia {
public:
  virtual std::string pobierzOpisStrategii() const = 0;
  virtual ~StrategiaZywienia() = default;
};

class Drapieznik : public StrategiaZywienia {
public:
  std::string pobierzOpisStrategii() const override {
    return "Drapieznik (wymaga miesa)";
  }
};

class Roslinozerca : public StrategiaZywienia {
public:
  std::string pobierzOpisStrategii() const override {
    return "Roslinozerca (wymaga roslin)";
  }
};

class Wszystkozerca : public StrategiaZywienia {
public:
  std::string pobierzOpisStrategii() const override {
    return "Wszystkozerca (je wszystko)";
  }
};

class Zwierze {
protected:
  std::unique_ptr<StrategiaZywienia> strategia;

public:
  Zwierze(std::unique_ptr<StrategiaZywienia> strat)
      : strategia(std::move(strat)) {}

  virtual std::string odglos() = 0;
  virtual std::string jedzenie() = 0;
  virtual double ileKalorii() = 0;
  virtual ~Zwierze() = default;

  void ustawStrategie(std::unique_ptr<StrategiaZywienia> nowaStrategia) {
    strategia = std::move(nowaStrategia);
  }

  std::string pokazJakJe() const {
    return strategia ? strategia->pobierzOpisStrategii() : "Brak strategii";
  }

  friend std::ostream &operator<<(std::ostream &os, Zwierze &z) {
    os << "To zwierze wydaje dzwiek: " << z.odglos() << ".\nJe " << z.jedzenie()
       << ", potrzebuje " << z.ileKalorii()
       << " kcal. Styl zycia: " << z.pokazJakJe() << "\n";
    return os;
  }
};

class Lew : public Zwierze {
public:
  Lew() : Zwierze(std::make_unique<Drapieznik>()) {}
  std::string odglos() override { return "Odgłos lwa"; }
  std::string jedzenie() override { return "Mięso";}  
  double ileKalorii() override { return 2348; }
};

class Slon : public Zwierze {
public:
  Slon() : Zwierze(std::make_unique<Roslinozerca>()) {}
  std::string odglos() override { return "Odgłos słonia"; }
  std::string jedzenie() override { return "Liście";}  
  double ileKalorii() override { return 20000; }
};

class Papuga : public Zwierze {
public:
  Papuga() : Zwierze(std::make_unique<Roslinozerca>()) {}
  std::string odglos() override { return "Odgłos papugii"; }
  std::string jedzenie() override { return "Ziarna"; }
  double ileKalorii() override { return 2; }
};

class Waz : public Zwierze {
public:
  Waz() : Zwierze(std::make_unique<Drapieznik>()) {}
  std::string odglos() override { return "Odgłos węża"; }
  std::string jedzenie() override { return "Mięso"; }
  double ileKalorii() override { return 387; }
};

std::unique_ptr<Zwierze> stworzZwierze(const std::string &gatunek) {
  if (gatunek == "Lew" || gatunek == "lew") {
    return std::make_unique<Lew>();
  } else if (gatunek == "Slon" || gatunek == "slon") {
    return std::make_unique<Slon>();
  } else if (gatunek == "Papuga" || gatunek == "papuga") {
    return std::make_unique<Papuga>();
  } else if (gatunek == "Waz" || gatunek == "waz") {
    return std::make_unique<Waz>();
  }
  return nullptr;
}

class Opiekun {
public:
  void nakarm() { std::cout << "Nakarmione" << std::endl; }
};

class Wybieg {
  Opiekun opiekun_wybiegu;

public:
  std::vector<std::unique_ptr<Zwierze>> zwierzeta;
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
    os << "[\n";
    for (auto &wybieg : z.wybiegi) {
      for (const auto &zwierze : wybieg->zwierzeta) {
        os << "  " << *zwierze;
      }
    }
    os << ']';
    return os;
  }
};

int main() {
  std::vector<std::unique_ptr<Zwierze>> zwierzeta;

  zwierzeta.push_back(stworzZwierze("Waz"));
  zwierzeta.push_back(stworzZwierze("Slon"));
  zwierzeta.push_back(stworzZwierze("Lew"));

  std::cout << "Przed zmianą strategii" << std::endl;
  std::cout << *zwierzeta[2];

  std::cout << "\n Dynamiczna podmiana strategii dla Lwa..." << std::endl;
  zwierzeta[2]->ustawStrategie(std::make_unique<Wszystkozerca>());

  std::cout << *zwierzeta[2];
  std::cout << "-------------------------------------------\n" << std::endl;

  Opiekun opiekun;
  std::vector<std::unique_ptr<Wybieg>> wybiegi;
  wybiegi.push_back(std::make_unique<Wybieg>(std::move(zwierzeta), opiekun));

  Zoo zoo = Zoo(std::move(wybiegi));
  std::cout << "Dzienna porcja kalorii w calym zoo: "
            << zoo.dziennaPorcjaKalorii() << " kcal\n"
            << std::endl;
  std::cout << zoo << std::endl;

  return 0;
}
