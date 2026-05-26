#include <iostream>

template <typename T, int N> void powtorz(const T &wartosc) {
  for (int i = 0; i < N; i++) {
    std::cout << wartosc;
  }
  std::cout << '\n';
}

int main() {
  powtorz<char, 5>('*'); // *****
  powtorz<int, 3>(7);    // 7 7 7
}
