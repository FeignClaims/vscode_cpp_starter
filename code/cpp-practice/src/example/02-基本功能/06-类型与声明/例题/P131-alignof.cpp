#include <iostream>
auto main() -> int {
  auto ac = alignof('c');
  auto ai = alignof(1);
  auto ad = alignof(2.0);

  int a[20];
  auto aa = alignof(a);

  std::cout << ac << ' ' << ai << ' ' << ad << ' ' << aa << '\n';
}