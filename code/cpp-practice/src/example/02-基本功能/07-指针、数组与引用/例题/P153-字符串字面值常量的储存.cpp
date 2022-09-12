#include <iostream>

auto main() -> int {
  const char* q{"Heraclitus"};
  const char* p{"Heraclitus"};

  if (p == q) {
    std::cout << "one!\n";
  }
}