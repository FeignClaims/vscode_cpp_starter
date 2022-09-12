int glob{};

constexpr void bad1(int a) {  // alert: constexpr 函数不能是 void
  glob = a;                   // alert: 在 constexpr 函数中有副作用
}

constexpr auto bad2(int a) -> int {
  // alert: 在 constexpr 函数中有 if 语句
  if (a >= 0) {
    return a;
  } else {
    return -a;
  }
}

constexpr auto bad3(int a) -> int {
  int sum{};                   // alert: 在 constexpr 函数中有局部变量
  for (int i{}; i < a; ++i) {  // alert: 在 constexpr 函数中有循环
    sum += i;
  }
  return sum;
}