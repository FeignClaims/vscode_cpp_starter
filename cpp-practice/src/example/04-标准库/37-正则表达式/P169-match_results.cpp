#include <format>
#include <iostream>
#include <regex>
#include <string>

auto main() -> int {
  std::regex pat{"(AAAA)(BBB)?"};
  std::string s{"AAAA"};
  std::smatch m;
  std::regex_search(s, m, pat);

  std::cout << std::format(
      "{}: {}\n", m[0].str(), m[0].matched);  // true：我们找到了一个匹配
  std::cout << std::format("{}: {}\n",
                           m[1].str(),
                           m[1].matched);  // true：存在第一个 sub_match
  std::cout << std::format("{}: {}\n",
                           m[2].str(),
                           m[2].matched);  // false：不存在第二个 sub_match
  std::cout << std::format("{}: {}\n",
                           m[3].str(),
                           m[3].matched);  // false：pat 不存在第三个 sub_match
}