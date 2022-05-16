#include <cstddef>
#include <iterator>
#include <type_traits>

template <typename T>
class InputIterator {
 public:
  bool value{true};
};

template <typename T>
constexpr auto InputIteratorValue() -> bool {
  return InputIterator<T>::value;
}

template <typename T>
class Vector1 {
 public:
  Vector1(std::size_t n, const T& val);  // n 个类型为 T 的元素，赋初值为 val

  // star: 引入 enable_if 作为默认模板实参
  template <typename Iter,
            typename = std::enable_if_t<InputIteratorValue<Iter>, Iter>>
  Vector1(Iter b, Iter e);  // 用 [b:e) 中的值进行初始化
  // ...
};

template <typename T>
class Vector2 {
 public:
  Vector2(std::size_t n, const T& val);  // n 个类型为 T 的元素，赋初值为 val

  // star: 引入 enable_if 作为构造函数实参类型
  template <typename Iter>
  Vector2(std::enable_if_t<InputIteratorValue<Iter>, Iter> b,
          Iter e);  // 用 [b:e) 中的值进行初始化
  // ...
};