class FloatW {
  double x;

public:
  explicit FloatW(double v) : x(v) {}
  double get() const { return x; }
};

int main() {
  FloatW a(3.14); // OK
  // FloatW b = 3.14; // Błąd: explicit uniemożliwia copy-initialization
  FloatW c{3.14}; // OK: jednolita inicjalizacja działa nawet z explicit
}
