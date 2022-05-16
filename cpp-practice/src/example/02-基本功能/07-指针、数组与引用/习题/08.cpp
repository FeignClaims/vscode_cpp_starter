#include <cstring>
#include <iostream>

auto main() -> int {
  char str[]{"a short string"};
  std::cout << sizeof(str) << ' ' << std::strlen(str);
}