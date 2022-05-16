constexpr auto isqrt_helper(int sq, int d, int a) -> int {
  return sq <= a ? isqrt_helper(sq + d, d + 2, a) : d;
}

constexpr auto isqrt(int x) -> int {
  return isqrt_helper(1, 3, x) / 2 - 1;
}