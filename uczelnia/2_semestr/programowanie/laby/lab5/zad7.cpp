// Przepisz poniższy kod, zastępując ręczną alokację obiektem unique_ptr.
// Upewnij się, że nie musisz pisać delete.

// Wersja z surowym wskaźnikiem:
double *wynik = new double(3.14);
std::cout << *wynik << '\n';
delete wynik;
// Twoja wersja z unique_ptr:
// ...
