#include <type_traits>

template <typename T>
class SmartPointer1 {
 public:
  auto operator*() -> T&;  // 返回指向整个对象的引用
  auto operator->()
      -> std::enable_if_t<std::is_class_v<T>, T>*;  // 选择一个成员（仅用于类）
};

template <typename T>
class SmartPointer2 {
 public:
  auto operator*() -> T&;  // 返回指向整个对象的引用

  auto operator->()
      -> T* requires std::is_class_v<T>;  // 选择一个成员（仅用于类）
};