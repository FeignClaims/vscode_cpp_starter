#include <cstddef>
#include <string>

auto main() -> int {
  std::string ss{"123.4567801234"};
  std::size_t dist{};              // 将读取的字符数保存在这里
  auto x = std::stoi(ss, &dist);   // x = 123（一个整数）
  ++dist;                          // 忽略小数点
  auto y = std::stoll(&ss[dist]);  // x= 4567801234（一个 long long）
}