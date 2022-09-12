#include <format>
#include <iostream>
#include <ranges>
#include <regex>
#include <string>

auto main() -> int {
  std::string input{"aa::bb cc::dd ee::ff"};
  std::regex pat{R"((\w+)([[:punct:]]+)(\w+)\s*)"};
  for (const auto& sub_match : std::ranges::subrange(
           std::sregex_token_iterator{input.begin(), input.end(), pat, {1, 3}},
           std::sregex_token_iterator{})) {
    std::cout << std::format("{}\n", sub_match.str());
  }
}