#include <cstdint>
#include <iostream>
#include <limits>

template <typename T>
void value();

auto main() -> int {
  value<bool>();
  value<char>();
  value<std::int16_t>();
  value<int>();
  value<std::int32_t>();
  value<std::int64_t>();
  value<float>();
  value<double>();
  value<long double>();
  value<unsigned>();
  value<std::uint32_t>();
}

template <typename T>
void value() {
  std::cout << std::numeric_limits<T>::max() << '\t'
            << std::numeric_limits<T>::min() << '\n';
}