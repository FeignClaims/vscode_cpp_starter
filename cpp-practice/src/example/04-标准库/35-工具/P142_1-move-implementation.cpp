#include <type_traits>

template <typename T>
auto move(T&& t) noexcept -> std::remove_reference_t<T> {
  return static_cast<std::remove_reference_t<T>&&>(t);
}