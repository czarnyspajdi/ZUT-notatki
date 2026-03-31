// Prześledź krok po kroku poniższy kod. Dla każdej linii zanotuj wartość ptr, *ptr 
// (jeśli dostępna) oraz czy pamięć jest zaalokowana.

int *ptr = nullptr;
ptr = new int(5);
std::cout << *ptr << '\n';
*ptr = *ptr + 3;
std::cout << *ptr << '\n';
delete ptr;
ptr = nullptr;
