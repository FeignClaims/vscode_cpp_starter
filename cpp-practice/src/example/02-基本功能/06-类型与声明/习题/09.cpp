#include <cstdint>
#include <iostream>
#include <limits>

template <typename T>
void size();

auto main() -> int {
  size<bool>();
  size<char>();
  size<std::int16_t>();
  size<int>();
  size<std::int32_t>();
  size<std::int64_t>();
  size<float>();
  size<double>();
  size<long double>();
  size<unsigned>();
  size<std::uint32_t>();
}

template <typename T>
void size() {
  std::cout << sizeof(T) << '\n';
}