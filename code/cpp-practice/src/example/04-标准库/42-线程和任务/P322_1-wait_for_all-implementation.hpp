#include <future>
#include <vector>
template <typename T>
auto wait_for_all(std::vector<std::future<T>>& vf) -> std::vector<T> {
  std::vector<T> res;
  for (auto& fu : vf) {
    res.push_back(fu.get());
  }
  return res;
}