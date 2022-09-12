#include <algorithm>
#include <memory>
#include <vector>

void user(std::vector<int> const& vx);

auto main() -> int {}

void user(std::vector<int> const& vx) {
  constexpr int kBufmax{1024};
  alignas(int) int buffer[kBufmax];  // STAR: 预留出未初始化的储存空间

  int const max = std::min(vx.size(), kBufmax / sizeof(int));
  std::uninitialized_copy(vx.begin(), vx.begin() + max, buffer);
  // ...
}