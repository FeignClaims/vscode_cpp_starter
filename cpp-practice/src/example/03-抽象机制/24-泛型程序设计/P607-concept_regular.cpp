#include <type_traits>
#include <utility>

template <typename T>
auto CopyEquality(T x) {  // 拷贝构造语义
  return T{x} == x;       // 副本应与源对象相等
}

template <typename T>
auto CopyAssignEquality(T x, T& y) {  // 赋值语义
  return (y = x, y == x);             // 复制结果应与源对象相等
}

template <typename T>
auto MoveEffect(T x, T& y) {  // 移动语义
  return (x == y ? T{std::move(x)} == y : true) && std::is_destructible_v<T>;
}

template <typename T>
auto MoveAssignEffect(T x, T& y, T& z) {  // 移动赋值语义
  return (y == z ? (x = std::move(y), x == z) : true) &&
         std::is_destructible_v<T>;
}