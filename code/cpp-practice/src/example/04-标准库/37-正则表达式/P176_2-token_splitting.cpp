#include <algorithm>
#include <format>
#include <iostream>
#include <iterator>
#include <ranges>
#include <regex>
#include <string>

void test2();
void test3();

auto main() -> int {
  test2();
  test3();
}

// STAR: 单词 splitting
void test2() {
  std::string s{"1,2 , 3 ,4,5, 6 7"};  // 输入
  std::regex pat{R"(\s*,\s*)"};        // 用逗号作为单词分隔符
  std::copy(std::sregex_token_iterator{s.begin(), s.end(), pat, -1},
            std::sregex_token_iterator{},
            std::ostream_iterator<std::string>{std::cout, "\n"});
}

// 等价的循环版本
void test3() {
  std::string s{"1,2 , 3 ,4,5, 6 7"};  // 输入
  std::regex pat{R"(\s*,\s*)"};        // 用逗号作为单词分隔符
  for (const auto& token : std::ranges::subrange(
           std::sregex_token_iterator{s.begin(), s.end(), pat, -1},
           std::sregex_token_iterator{})) {
    std::cout << std::format("{}\n", token.str());
  }
}