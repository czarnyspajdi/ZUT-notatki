#include <iostream>
#include <memory>

class StrategiaPodatkowa {
public:
  virtual double oblicz(double kwota) const = 0;
  virtual ~StrategiaPodatkowa() = default;
};

class PodatekLiniowy : public StrategiaPodatkowa {
  const double procent = 0.19;

public:
  double oblicz(double kwota) const override { return kwota * procent; }
};

class PodatekProgresywny : public StrategiaPodatkowa {
  const double prog_1 = 0.19;
  const double prog_2 = 0.8;

public:
  double oblicz(double kwota) const override {
    return (kwota < 4000) ? (kwota * prog_1) : (kwota * prog_2);
  }
};

class BrakPodatku : public StrategiaPodatkowa {
public:
  double oblicz(double) const override { return 0.0; }
};

class Faktura {
  std::unique_ptr<StrategiaPodatkowa> strategia;
  double kwota;

public:
  Faktura(std::unique_ptr<StrategiaPodatkowa> s, double kwota)
      : strategia(std::move(s)), kwota(kwota) {}

  double kwotaDoZaplaty() const { return strategia->oblicz(kwota) + kwota; }
};

int main() {
  Faktura faktura_socjalistyczna(std::make_unique<PodatekProgresywny>(), 5000);
  Faktura faktura_wolnorynkowa(std::make_unique<PodatekLiniowy>(), 5000);
  Faktura faktura_libertalinistyczna(std::make_unique<BrakPodatku>(), 5000);

  std::cout << faktura_socjalistyczna.kwotaDoZaplaty() << std::endl;
  std::cout << faktura_wolnorynkowa.kwotaDoZaplaty() << std::endl;
  std::cout << faktura_libertalinistyczna.kwotaDoZaplaty() << std::endl;
}
