#include <cstddef>
#include <iostream>
#include <type_traits>
#include <utility>

template <std::size_t N>  // 打印第 N 个及之后的元素
class PrintTuple {
 public:
  template <typename... T>
  static auto print(std::ostream& os, const std::tuple<T...>& t)
      -> std::enable_if_t<(N < sizeof...(T))> {  // 非空元组
    os << ", " << std::get<N>(t);                // 打印一个元素
    PrintTuple<N + 1>()(os, t);                  // 打印剩余元素
  }

  template <typename... T>
  static auto print(std::ostream&, const std::tuple<T...>&)
      -> std::enable_if_t<!(N < sizeof...(T))> {  // 空元组
  }
};

template <typename T0, typename... T>
auto operator<<(std::ostream& os, const std::tuple<T0, T...>& t)
    -> std::ostream& {          // 非空元组
  os << '{' << std::get<0>(t);  // 打印第一个元素
  PrintTuple<1>::print(os, t);  // 打印剩余元素
  return os << '}';
}

auto operator<<(std::ostream& os, const std::tuple<>&)
    -> std::ostream& {  // 空元组
  return os << "{}";
}