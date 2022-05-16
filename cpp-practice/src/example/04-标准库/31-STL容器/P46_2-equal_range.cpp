#include <format>
#include <iostream>
#include <map>
#include <ranges>
#include <string>

auto main() -> int {
  std::multimap<std::string, int> mm{
      {"apple", 2}, {"pear", 2}, {"apple", 7}, {"orange", 2}, {"apple", 9}};
  const std::string k{"apple"};
  if (auto pp = mm.equal_range(k); pp.first == pp.second) {
    std::cout << std::format("no element with value {}\n", k);
  } else {
    std::cout << std::format("elements with value {}:\n", k);
    for (const auto& [_, v] : std::ranges::subrange(pp.first, pp.second)) {
      std::cout << std::format("{} ", v);
    }
  }
}