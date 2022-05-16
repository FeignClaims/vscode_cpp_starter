#include <memory>

auto make_sequence(int n) -> std::unique_ptr<int[]> {
  std::unique_ptr<int[]> p{new int[n]};
  for (int i{}; i < n; ++i) {
    p[i] = i;
  }
  return p;
}