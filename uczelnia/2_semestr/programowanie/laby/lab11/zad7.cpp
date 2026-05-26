#include <iostream>
#include <string>
#include <vector>

template <typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &v) {
  os << "[";
  for (size_t i = 0; i < v.size(); ++i) {
    os << v[i];
    if (i != v.size() - 1)
      os << ", ";
  }
  os << "]";
  return os;
}

template <typename T1, typename T2> class Para {
  T1 pierwszy;
  T2 drugi;

public:
  Para(const T1 &p, const T2 &d) : pierwszy(p), drugi(d) {}

  const T1 &pobierzPierwszy() const { return pierwszy; }
  const T2 &pobierzDrugi() const { return drugi; }

  friend std::ostream &operator<<(std::ostream &os, const Para<T1, T2> &para) {
    os << "(" << para.pierwszy << ", " << para.drugi << ")";
    return os;
  }
};

int main() {
  Para<int, std::string> p1(42, "Tralala");
  std::cout << "Para 1: " << p1 << "\n";
  std::cout << "Pierwszy element p1: " << p1.pobierzPierwszy() << "\n\n";

  Para<double, double> p2(3.1415, 2.7182);
  std::cout << "Para 2: " << p2 << "\n";
  std::cout << "Drugi element p2: " << p2.pobierzDrugi() << "\n\n";

  std::vector<int> liczby = {1, 1, 2, 3, 5, 8};
  Para<std::string, std::vector<int>> p3("Fibonacci", liczby);

  std::cout << "Para 3: " << p3 << "\n";

  return 0;
}
