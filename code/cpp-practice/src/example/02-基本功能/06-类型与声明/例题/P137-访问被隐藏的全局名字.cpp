#include <iostream>

constexpr int kX{};

auto main() -> int {
  constexpr int kX{1};
  std::cout << kX << ' ' << ::kX;
}