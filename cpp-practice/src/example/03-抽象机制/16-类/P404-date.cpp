#include "P404-date.hpp"

namespace chrono {
Date::Date(int dd, Month mm, int yy)
    : d{dd ? dd : default_date().d},
      m{static_cast<int>(mm) ? mm : default_date().m},
      y{yy ? yy : default_date().y} {
  if (!is_valid()) throw BadDate{};
}

auto Date::is_valid() -> bool {
  return is_date(d, static_cast<Month>(m), y);
}

auto Date::add_month(int n) -> Date& {
  if (!n) return *this;
  if (n > 0) {
    int delta_y{n / kMonthPerYear};                   // 整年数
    int mm{static_cast<int>(m) + n % kMonthPerYear};  // 剩余月数
    if (mm > kMonthPerYear) {  // 注意：dec 用 12 表示
      ++delta_y;
      mm -= kMonthPerYear;
    }

    // ... 处理 mm 月没有第 d 天的情况 ...

    y += delta_y;
    m = static_cast<Month>(mm);
    return *this;
  }

  // ... 处理负数 n...

  return *this;
}

auto default_date() -> const Date& {
  static Date d{1, Month::kJan, 1970};
  return d;
}

auto is_date(int d, Month m, int y) -> bool {
  int ndays{};
  switch (m) {
    case Month::kFeb:
      ndays = kDayPerFeb + is_leapyear(y);
      break;
    case Month::kApr:
    case Month::kJun:
    case Month::kSep:
    case Month::kNov:
      ndays = kDayPerMonthLess;
      break;
    case Month::kJan:
    case Month::kMar:
    case Month::kMay:
    case Month::kJul:
    case Month::kAug:
    case Month::kOct:
    case Month::kDec:
      ndays = kDayPerMonthMore;
      break;
    default:
      return false;
  }
  return 1 <= d && d <= ndays;
}
}  // namespace chrono