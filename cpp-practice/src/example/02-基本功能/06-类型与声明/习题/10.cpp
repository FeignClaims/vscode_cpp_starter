#include <cstdint>
#include <iostream>
#include <limits>

template <typename T>
void alignment();

auto main() -> int {
  alignment<bool>();
  alignment<char>();
  alignment<std::int16_t>();
  alignment<int>();
  alignment<std::int32_t>();
  alignment<std::int64_t>();
  alignment<float>();
  alignment<double>();
  alignment<long double>();
  alignment<unsigned>();
  alignment<std::uint32_t>();
}

template <typename T>
void alignment() {
  std::cout << alignof(T) << '\n';
}