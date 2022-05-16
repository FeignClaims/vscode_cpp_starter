#include <vector>
template <typename T>
void call_f(std::vector<T>& v) noexcept(noexcept(f(v[0]))) {
  for (auto x : v) {
    f(x);
  }
}