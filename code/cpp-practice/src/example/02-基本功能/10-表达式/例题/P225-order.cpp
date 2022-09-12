#include <iostream>
#include <vector>

auto main() -> int {
  std::vector<int> v{9, 9, 9};
  int i{1};
  v[i] = i++;  // 未定义的结果（v[1] = 1？v[2] = 1？）
  for (auto x : v) {
    std::cout << x << ' ';
  }
}