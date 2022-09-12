// 操作一个名为 nm 的二维矩阵
#include <iostream>
void do_something(int i, int j) {
  constexpr int kN{10};
  constexpr int kM{10};
  int nm[kN][kM]{};
  int a{};

  for (i = 0; i != kN; ++i) {
    for (j = 0; j != kM; ++j) {
      if (nm[i][j] == a) {
        goto found;
      }
    }
  }

// ...
found:
  // nm[i][j] == a
  std::cout << nm[i][j] << '\n';
}