#include <mutex>
#include <string>

struct Color {
  std::string color;
};

auto read_from_environment(std::string s) -> std::string {
  return s;
}

auto default_color1() -> Color& {  // 用户代码
  static Color def{"background color"};
  return def;
}

auto default_color2() -> Color& {  // 编译器实际生成的代码
  static Color def;
  std::once_flag __def;
  std::call_once(__def, read_from_environment, "background color");
  return def;
}