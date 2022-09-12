#include <iostream>
#include <string>

namespace chrono {
enum class Month {
  kJan = 1,
  kFeb,
  kMar,
  kApr,
  kMay,
  kJun,
  kJul,
  kAug,
  kSep,
  kOct,
  kNov,
  kDec
};

class Date {
 public:             // 公共接口：
  class BadDate {};  // 异常类

  explicit Date(int dd = {}, Month mm = {}, int yy = {});  // 表示“选择默认值”

  // 非修改性函数，用于查询 Date:
  [[nodiscard]] auto day() const -> int { return d; }
  [[nodiscard]] auto month() const -> Month { return m; }
  [[nodiscard]] auto year() const -> int { return y; }

  [[nodiscard]] auto string_rep() const -> std::string;  // 字符串表示
  void char_rep(char s[], int max) const;  // C 风格字符串表示

  // 修改性函数，用于改变 Date:
  auto add_year(int n) -> Date&;   // 增加 n 年
  auto add_month(int n) -> Date&;  // 增加 n 月
  auto add_day(int n) -> Date&;    // 增加 n 天
 private:
  auto is_valid() -> bool;  // 检查 Date 是否表示一个日期

  int d;
  Month m;
  int y;
};

constexpr int kMonthPerYear{12};
constexpr int kDayPerFeb{28};
constexpr int kDayPerMonthLess{30};
constexpr int kDayPerMonthMore{31};

auto default_date() -> const Date&;

auto is_date(int d, Month m, int y) -> bool;  // 对合法日期返回 true
auto is_leapyear(int y) -> bool;              // 若 y 是闰年返回 true

auto operator==(const Date& a, const Date& b) -> bool {
  return a.day() == b.day() && a.month() == b.month() && a.year() == b.year();
}
auto operator!=(const Date& a, const Date& b) -> bool {
  return !(a == b);
}

auto operator<<(std::ostream& os, const Date& d)
    -> std::ostream&;  // 将 d 打印到 os
auto operator>>(std::istream& is, Date& d)
    -> std::istream&;  // 从 is 读取 Date 存入 d
}  // namespace chrono
