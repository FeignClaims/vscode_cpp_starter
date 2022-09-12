#ifndef QUANTITY_HPP
#define QUANTITY_HPP

#include "P695-si_units_example-unit.hpp"

#include <string>

template <typename U, typename T = double>
struct Quantity {
  explicit constexpr Quantity(double d) : val{d} {}

  T val;
};

template <typename U>
auto operator+(Quantity<U> x, Quantity<U> y) -> Quantity<U> {  // 相同量纲
  return Quantity<U>{x.val + y.val};
}

template <typename U>
auto operator-(Quantity<U> x, Quantity<U> y) -> Quantity<U> {  // 相同量纲
  return Quantity<U>{x.val - y.val};
}

template <typename U1, typename U2>
auto operator*(Quantity<U1> x, Quantity<U2> y) -> Quantity<UnitPlus<U1, U2>> {
  return Quantity<UnitPlus<U1, U2>>{x.val * y.val};
}
template <typename U>
auto operator*(Quantity<U> x, double y) -> Quantity<U> {
  return Quantity<U>{x.val * y};
}
template <typename U>
auto operator*(double y, Quantity<U> x) -> Quantity<U> {
  return Quantity<U>{y * x.val};
}

template <typename U1, typename U2>
auto operator/(Quantity<U1> x, Quantity<U2> y) -> Quantity<UnitMinus<U1, U2>> {
  return Quantity<UnitMinus<U1, U2>>{x.val / y.val};
}
template <typename U>
auto operator/(Quantity<U> x, double y) -> Quantity<U> {
  return Quantity<U>{x.val / y};
}
template <typename U>
auto operator/(double y, Quantity<U> x) -> Quantity<U> {
  return Quantity<U>{y / x.val};
}

constexpr auto operator""_m(long double d) -> Quantity<M> {
  return Quantity<M>{static_cast<double>(d)};
}
constexpr auto operator""_kg(long double d) -> Quantity<Kg> {
  return Quantity<Kg>{static_cast<double>(d)};
}
constexpr auto operator""_s(long double d) -> Quantity<S> {
  return Quantity<S>{static_cast<double>(d)};
}

template <typename U>
auto operator==(Quantity<U> x, Quantity<U> y) -> bool {
  return x.val == y.val;
}
template <typename U>
auto operator!=(Quantity<U> x, Quantity<U> y) -> bool {
  return x.val != y.val;
}

template <typename U>
auto square(Quantity<U> x) -> Quantity<UnitPlus<U, U>> {
  return Quantity<UnitPlus<U, U>>(x.val * x.val);
}

auto suffix(int u, const char* x) -> std::string {  // 辅助函数
  std::string suf;
  if (u) {
    suf += x;
    if (1 < u) suf += std::to_string('0' + u);
    if (u < 0) {
      suf += '-';
      suf += std::to_string('0' - u);
    }
  }
  return suf;
}
template <typename U>
auto operator<<(std::ostream& os, Quantity<U> v) -> std::ostream& {
  return os << v.val << suffix(U::m, "m") << suffix(U::kg, "kg")
            << suffix(U::s, "s");
}

#endif