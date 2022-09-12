#include <iostream>

auto main() -> int {
  const int& cdr{1};
  std::cout << cdr;
}