template <typename T>
class Ptr {
 public:
  template <int N>
  Ptr(T* p, T (&a)[N]);  // 绑定到数组 a，sz == N，初始值是 p
  Ptr(T* p, T* a, int s);  // 绑定到数组 a，数组的大小是 s，初始值是 p

  // STAR: 前置和后置递增/递减运算符的重载
  auto operator++() -> Ptr&;    // 前置
  auto operator++(int) -> Ptr;  // 后置

  auto operator--() -> Ptr&;    // 前置
  auto operator--(int) -> Ptr;  // 后置

  auto operator*() -> T&;  // 前置

 private:
  T* ptr;
  T* array;
  int sz;
};

template <typename T>
auto Ptr<T>::operator++() -> Ptr& {  // 递增后返回当前对象
  // ...检查 ptr + 1 是否有效...
  return *++ptr;
}

template <typename T>
auto Ptr<T>::operator++(int) -> Ptr {  // 递增并返回 Ptr 的旧值
  // ...检查 ptr + 1 是否有效...
  Ptr old{ptr, array, sz};
  ++ptr;
  return old;
}