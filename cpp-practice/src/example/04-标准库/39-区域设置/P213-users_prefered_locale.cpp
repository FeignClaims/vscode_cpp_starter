#include <format>
#include <iostream>
#include <locale>

auto main() -> int {
  std::locale loc{""};
  std::cout << std::format("{}\n", loc.name());
}