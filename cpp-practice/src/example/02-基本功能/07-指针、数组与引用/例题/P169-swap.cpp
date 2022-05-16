#include <utility>
// STAR: swap 的实现
template <typename T>
void swap(T& a, T& b) {
  T temp{std::move(a)};
  a = std::move(b);
  b = std::move(temp);
}

template <typename T>
void swap(T&& a, T& b) {
  T temp{a};
  a = std::move(b);
  b = std::move(temp);
}

template <typename T>
void swap(T& a, T&& b) {
  T temp{std::move(a)};
  a = b;
  b = std::move(temp);
}