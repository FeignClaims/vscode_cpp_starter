constexpr auto ipow(int x, int n) -> int {  // 对 n >= 0 求 n 次方
  return (n > 0) ? x * ipow(x, n - 1) : 1;
}

template <char c>
constexpr auto b3_helper() -> int {  // 处理一个三进制数字
  static_assert(c < '3', "not a ternary digit");
  return c;
}

template <char c, char... tail>  // 剥离一个数字
constexpr auto b3_helper() -> int {
  static_assert(c < '3', "not a ternary digit");
  return ipow(3, sizeof...(tail)) * (c - '0') + b3_helper(tail...);
}

template <char... chars>
constexpr auto operator""_b3() -> int {  // 三进制
  return b3_helper(chars...);
}