// Prześledź poniższy kod. Przed każdym std::cout przewidź wartość use_count(), a nast
// pnie uruchom program i porównaj

#include <iostream>
#include <memory>

int main() {
  auto a = std::make_shared<int>(42);
  std::cout << a.use_count() << '\n'; // 1
  {
    auto b = a;
    std::cout << a.use_count() << '\n'; // 2
    auto c = a;
    std::cout << a.use_count() << '\n'; // 3
  }
  std::cout << a.use_count() << '\n'; // 1
}
