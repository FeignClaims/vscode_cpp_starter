#include <format>
#include <iostream>
#include <regex>
#include <string>

auto main() -> int {
  std::string input{"x 1 y2 22 zaq 34567"};
  std::regex pat{R"((\w+)\s(\d+))"};  // 单词 空白符 数值
  std::string format{"{$2,$1}\n"};

  std::cout << std::format("{}\n", std::regex_replace(input, pat, format));
  std::cout << std::format(
      "{}\n",
      std::regex_replace(
          input,
          pat,
          format,
          std::regex_constants::format_no_copy));  //\* 不复制未匹配字符
}