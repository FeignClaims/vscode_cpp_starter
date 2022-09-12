#include <iostream>

struct arr {
  int i[10]{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
};

int a[10]{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

void bound(int* a);

auto main() -> int {
  int b[10]{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  int* c = new int[10]{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  arr d{};

  bound(a);
  bound(b);
  bound(c);
  bound(d.i);

  std::cin.get();
}

void bound(int* a) {
  a[10] = 10;
  a[100] = 100;
  a[-10] = -10;
  a[-100] = -100;
}