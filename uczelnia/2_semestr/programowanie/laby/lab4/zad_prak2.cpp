#include <iostream>

class Data {
  int rok, miesiac, dzien;
  long int czas;

public:
  Data(int rok, int miesiac, int dzien)
      : rok(rok), miesiac(miesiac), dzien(dzien) {}
  Data() : rok(2026), miesiac(3), dzien(24) {}

  Data(long int czas = 1000) {}

  void pokaz() {
    std::cout << rok << '-' << miesiac << '-' << dzien << std::endl;
  }
};

int main() {
  Data d1(2021, 12, 31);
  Data d2 = {2022, 1, 15};
  Data d3{};
  d1.pokaz(); // 2021-12-31
  d2.pokaz(); // 2022-1-15
  d3.pokaz(); // dzisiejsza data
}
