template <typename T> T wiekszy(T a, T b) { return a > b ? a : b; }

int main() {
  wiekszy(2, 5);     // int int
  wiekszy(2.0, 5.0); // double double
  // wiekszy(2, 5.0); // nie uruchomi się, bowiem zadeklarowalilśmy dwa 
  // argumenty tego samego typu, a podajemy dwa różne
  wiekszy<double>(2, 5.0); // double
  wiekszy('A', 'Z');       // char
}
