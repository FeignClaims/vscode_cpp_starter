#include <cstddef>
#include <ios>
#include <iostream>
#include <locale>
#include <string>

class MyPunct : public std::numpunct<char> {
 public:
  explicit MyPunct(std::size_t r = {}) : std::numpunct<char>(r) {}

 protected:
  [[nodiscard]] auto do_decimal_point() const -> char override {
    return ',';  // 逗号
  }
  [[nodiscard]] auto do_thousands_sep() const -> char override {
    return '_';  // 下划线
  }
  [[nodiscard]] auto do_grouping() const -> std::string override {
    return "\003";  // 三个数字一个分组
  }
};

auto main() -> int {
  std::cout << "style A: " << 12345678 << " *** " << 1234567.8 << " *** "
            << std::fixed << 1234567.8 << '\n';
  std::cout << std::defaultfloat;  // 重设浮点数格式
  std::locale loc{std::locale{}, new MyPunct{}};
  std::cout.imbue(loc);
  std::cout << "style B: " << 12345678 << " *** " << 1234567.8 << " *** "
            << std::fixed << 1234567.8 << '\n';
}