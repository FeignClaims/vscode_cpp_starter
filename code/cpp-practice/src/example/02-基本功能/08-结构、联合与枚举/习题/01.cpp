#include <cstdint>
#include <iostream>

struct All {
  char c;
  bool b;
  int i;
  std::int32_t l;
  double d;
  long double ld;
};

auto main() -> int {
  std::cout << sizeof(All) << '\n';
}