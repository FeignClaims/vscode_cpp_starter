#ifndef UNIT_HPP
#define UNIT_HPP

template <int M, int K, int S>
struct Unit {
  enum { m = M, kg = K, s = S };
};

using M = Unit<1, 0, 0>;      // 米
using Kg = Unit<0, 1, 0>;     // 千克
using S = Unit<0, 0, 1>;      // 秒
using MpS = Unit<1, 0, -1>;   // 米每秒 (米 / 秒)
using MpS2 = Unit<1, 0, -2>;  // 米每平方秒 (米 /(秒 * 秒)

template <typename U1, typename U2>
struct Uplus {
  using type = Unit<U1::m + U2::m, U1::kg + U2::kg, U1::s + U2::s>;
};

template <typename U1, typename U2>
struct Uminus {
  using type = Unit<U1::m - U2::m, U1::kg - U2::kg, U1::s - U2::s>;
};

template <typename U1, typename U2>
using UnitPlus = typename Uplus<U1, U2>::type;

template <typename U1, typename U2>
using UnitMinus = typename Uminus<U1, U2>::type;

#endif