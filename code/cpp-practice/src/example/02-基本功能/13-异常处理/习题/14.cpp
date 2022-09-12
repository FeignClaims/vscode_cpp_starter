#include <limits>
#include <stdexcept>

template <typename T>
auto plus(T a, T b) -> T {
  if (std::numeric_limits<T>::max() - a < b) {
    throw std::overflow_error{""};
  }
  return a + b;
}

template <typename T>
auto minus(T a, T b) -> T {
  if (std::numeric_limits<T>::min() + b > a) {
    throw std::underflow_error{""};
  }
  return a - b;
}

template <typename T>
auto multiply(T a, T b) -> T {
  if (std::numeric_limits<T>::max() / a < b) {
    throw std::overflow_error{""};
  }
  return a * b;
}

template <typename T>
auto divide(T a, T b) -> T {
  if (b == 0) {
    throw std::overflow_error{""};
  }
  return a / b;
}