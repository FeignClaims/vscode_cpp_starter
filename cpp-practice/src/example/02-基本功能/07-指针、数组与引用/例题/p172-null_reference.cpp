#include <iostream>
auto ident(char* p) -> char* {
  return p;
}

auto main() -> int {
  char& r{*ident(nullptr)};  // STAR: 无效代码
  std::cout << r;
}