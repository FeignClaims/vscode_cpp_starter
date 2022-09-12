#include <iostream>

auto main() -> int {
  for (int i{}; auto x : {4, 5, 9, 17, 12}) {
    if (++i == 1) {
      std::cout << x;
    } else {
      std::cout << ' ' << x;
    }
  }

  return 0;
}