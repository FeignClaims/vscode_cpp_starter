#include <format>
#include <iostream>
#include <sstream>

auto main() -> int {
  std::ostringstream oss{"Label: ", std::ios::ate};  // 在尾部写
  std::cout << std::format("{}\n", oss.str());       // 输出 "Label: "
  oss << "val";
  std::cout << std::format(
      "{}\n",
      oss.str());  // 输出 "Label: val"（"val" 追加在 "Label: " 之后

  std::ostringstream oss2{"Label: "};            // 在头部写
  std::cout << std::format("{}\n", oss2.str());  // 输出 "Label: "
  oss2 << "val";
  std::cout << std::format(
      "{}\n", oss2.str());  // 输出 "valel: "（"val" 覆盖了 "Label: "）
}