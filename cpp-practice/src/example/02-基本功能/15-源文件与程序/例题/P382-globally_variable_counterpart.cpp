#include <iostream>

// STAR: 通常返回引用的函数可以很好地替代全局变量
auto use_count() -> int& {
  static int uc{};
  return uc;
}

void f() {
  std::cout << ++use_count();  // 读取并递增
  // ...
}