bool czyParzysta(int n);
int poleProstokata(int a, int b);
double srednia(int a, int b, int c);

bool czyParzysta(int n) { return n % 2 == 0; }

int poleProstokata(int a, int b) { return a * b; }

double srednia(int a, int b, int c) { return (double)(a + b + c) / 3; }
