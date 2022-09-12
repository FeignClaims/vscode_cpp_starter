#include <iostream>
#include <string>

auto main() -> int {
  // STAR: 原始字符串字面值中允许出现真正的换行、制表
  std::string counts{R"(1
  22
333)"};

  std::cout << counts << '\n';
}