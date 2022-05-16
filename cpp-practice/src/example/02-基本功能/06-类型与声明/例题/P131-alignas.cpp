#include <algorithm>
#include <memory>
#include <vector>

void user(const std::vector<int>& vx);

auto main() -> int {
}

void user(const std::vector<int>& vx) {
  constexpr int kBufmax{1024};
  alignas(int) buffer[kBufmax];  // STAR: 预留出未初始化的储存空间

  const int max = std::min(vx.size(), kBufmax / sizeof(int));
  std::uninitialized_copy(vx.begin(), vx.begin() + max, buffer);
  // ...
}