#include <cstddef>
auto mycat(const char* a, const char* b) -> char* {
  auto len = [](const char* str) {
    std::size_t i{};
    while (str[i] != '\0') {
      ++i;
    }
    return i;
  };
  std::size_t size_a{len(a)};
  std::size_t size_b{len(b)};
  char* res{new char[size_a + size_b + 1]};
  for (std::size_t i{}; i < size_a; ++i) {
    res[i] = a[i];
  }
  for (std::size_t i{size_a}; i < size_b; ++i) {
    res[i] = b[i];
  }
  res[size_a + size_b] = '\0';
  return res;
}