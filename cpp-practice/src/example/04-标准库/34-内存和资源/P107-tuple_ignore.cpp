#include <format>
#include <iostream>
#include <string>
#include <tuple>

auto main() -> int {
  auto t = std::make_tuple(2.71828, 29979292458, "Hannibal");
  double c{};
  std::string name;
  std::tie(c, std::ignore, name) = t;  // c = 2.71828；name = "Hannibal"
  std::cout << std::format("{} {}\n", c, name);
}