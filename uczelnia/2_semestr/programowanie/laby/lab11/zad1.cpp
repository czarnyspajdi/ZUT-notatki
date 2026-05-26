#include <cmath>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

class Ksztalt {
public:
  virtual ~Ksztalt() = default;
  virtual double pole() = 0;
  virtual std::string opis() = 0;
};

class Kolo : public Ksztalt {
  int r;

public:
  Kolo(int r) : r(r) {}

  double pole() override { return r * r * M_PI; }
  std::string opis() override { return "To jest koło";}  

  ~Kolo() override {}
};

class Trojkat : public Ksztalt {
  int a, h;

public:
  Trojkat(int a, int h) : a(a), h(h) {}

  double pole() override { return a * h * 0.5; }
  std::string opis() override { return "To jest trójkąt";}   

  ~Trojkat() override {}
};

class Kwadrat : public Ksztalt {
  int a;

public:
  Kwadrat(int a) : a(a) {}

  double pole() override { return a * a; }
  std::string opis() override { return " To jest kwadrat"; }

  ~Kwadrat() override {}
};

double sum_pole(std::vector<std::unique_ptr<Ksztalt>> &vec) {
  double sum = 0;
  for (auto &ksztalt : vec) {
    sum += ksztalt->pole();
  }
  return sum;
}

int main() {
  std::vector<std::unique_ptr<Ksztalt>> vec;
  vec.push_back(std::make_unique<Trojkat>(2, 4));
  vec.push_back(std::make_unique<Kolo>(2));
  vec.push_back(std::make_unique<Kwadrat>(4));
  std::cout << "Suma pól wszystkich figur to: " << sum_pole(vec) << std::endl;
}
