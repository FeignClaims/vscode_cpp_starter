#include <type_traits>
#include <utility>

template <typename T>
void swap(T& a, T& b) noexcept(std::is_nothrow_move_assignable_v<T>&&
                                   std::is_nothrow_move_assignable_v<T>) {
  T temp{std::move(a)};
  a = std::move(b);
  b = std::move(temp);
}