#include <format>
#include <iostream>
#include <ranges>
#include <regex>
#include <string>

auto main() -> int {
  std::string input{"aa as; asd ++e^asdf asdfg"};
  std::regex pat{R"(\s+(\w+))"};
  for (const auto& match : std::ranges::subrange(
           std::sregex_iterator{input.begin(), input.end(), pat},
           std::sregex_iterator{})) {
    std::cout << std::format("{}\n", match.str());
  }
}