#include "P229-handle_ioexception.hpp"
#include "P233-specialized_money_format.hpp"

#include <cstdint>
#include <ios>
#include <locale>
#include <ostream>
#include <sstream>

struct Money {                 // 保存货币金额的简单类型
  using Value = std::int64_t;  // 用于遭受了通货膨胀的货币
  Value amount;
};

auto operator<<(std::ostream& s, Money m) -> std::ostream& {
  std::ostream::sentry guard{s};
  if (!guard) return s;

  try {
    const auto& f = std::use_facet<std::money_put<char>>(s.getloc());
    if (m.amount == static_cast<std::int64_t>(m.amount)) {
      if (f.put(s, true, s, s.fill(), m.amount).failed()) {
        s.setstate(std::ios_base::badbit);
      }
    } else {
      std::ostringstream v;
      v << m;  // 转换为字符串表示
      if (f.put(s, true, s, s.fill(), v.str()).failed()) {
        s.setstate(std::ios_base::badbit);
      }
    }
  } catch (...) {
    handle_ioexception(s);
  }
  return s;
}