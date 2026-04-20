#include <stdio.h>
#include <string>
#include <vector>

class Student {
  std::string imie;
  std::vector<double> oceny;

public:
  Student(std::string imie) : imie(imie) {}

  void dodajOcene(double ocena) { oceny.push_back(ocena); }
  double srednia() const {
    double sum = 0;
    for (double ocena : oceny) {
      sum += ocena;
    }
    double avg = sum / oceny.size();
    return avg;
  }

  void wypisz() const {
    printf("Imie %s\n", imie.c_str());
    printf("Oceny:\n");
    for (double ocena : oceny) {
      printf("- %0.1f\n", ocena);
    }
    printf("Średnia: %0.2f\n", srednia());
  }
};

class Dziennik {
  std::vector<std::reference_wrapper<Student>> studenci;

public:
  void zarejestruj(Student &s) { studenci.push_back(s); }
  void dodajOceneWszystkim(double ocena) {
    for (Student &student : studenci) {
      student.dodajOcene(ocena);
    }
  }

  void raport() const {
    printf("--- Wszyscy studenci ---\n");
    for (const Student student : studenci) {
      student.wypisz();
    }
  }
};

int main() {
  Student s1 = Student("Bogdan");
  Student s2 = Student("Wojciech");

  Dziennik dziennik = Dziennik();
  dziennik.zarejestruj(s1);
  dziennik.zarejestruj(s2);
  dziennik.dodajOceneWszystkim(5);
  dziennik.raport();
}
