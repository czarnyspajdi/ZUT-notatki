#include <iostream>
#include <stdexcept>
#include <string>

struct Student {
  std::string imie;
  std::string numerIndexu;
  Student(std::string imie, std::string numerIndexu)
      : imie(imie), numerIndexu(numerIndexu) {}
  Student() {}
};

class Kurs {
  const int max_student = 30;
  int current_student = 0;
  Student *studenci;

public:
  Kurs() : studenci(new Student[max_student]) {}
  void zapiszStudenta(Student student) {
    if (current_student >= max_student) {
      throw std::range_error("You can't add more students!");
    }
    studenci[current_student++] = student;
  }

  void wypiszStudentów() {
    for (int i = 0; i < current_student; i++) {
      std::cout << "=== Student ===\n";
      std::cout << "- Imię : " << studenci[i].imie << '\n';
      std::cout << "- Numer indeksu : " << studenci[i].numerIndexu << std::endl;
    }
  }
};

int main() {
  Student bogdan = Student("Bogdan", "23894");
  Student stanislaw = Student("Stanisław", "238947");
  Kurs matematyka = Kurs();
  Kurs programowanie = Kurs();
  matematyka.zapiszStudenta(bogdan);
  matematyka.zapiszStudenta(stanislaw);
  programowanie.zapiszStudenta(bogdan);
  std::cout << "\nKurs matematyki:\n" << std::endl;
  matematyka.wypiszStudentów();
  std::cout << "\nKurs programowania:\n" << std::endl;
  programowanie.wypiszStudentów();
}
