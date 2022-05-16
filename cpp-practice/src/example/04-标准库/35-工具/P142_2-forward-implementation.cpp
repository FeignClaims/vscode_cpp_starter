#include <type_traits>

template <typename T>
auto forward(std::remove_reference_t<T>& t) noexcept -> T&& {
  return static_cast<T&&>(t);
}

template <typename T>
auto forward(std::remove_reference_t<T>&& t) noexcept -> T&& {
  static_assert(!std::is_lvalue_reference_v<T>, "forward of lvalue");
  return static_cast<T&&>(t);
}