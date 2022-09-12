#include <string>
#include <type_traits>

constexpr int kOnStackMax{
    sizeof(std::string)};  // 我们希望在栈中分配的最大对象大小

template <typename T>
class OnHeap {
 public:
  OnHeap() : p{new T} {}           // 分配
  OnHeap(const OnHeap&) = delete;  // 阻止拷贝

  auto operator=(const OnHeap&) = delete;

  ~OnHeap() { delete p; }  // 释放

  auto operator*() -> T& { return *p; }
  auto operator->() -> T* { return p; }

 private:
  T* p;  // 指向自由存储空间中对象的指针
};

template <typename T>
class Scoped {
 public:
  Scoped(const Scoped&) = delete;  // 阻止拷贝

  auto operator=(const Scoped&) -> Scoped = delete;

  auto operator*() -> T& { return x; }
  auto operator->() -> T* { return &x; }

 private:
  T x;  // 对象本身
};

template <typename T>
class ObjHolder {
 public:
  // STAR: std::conditional 是编译时编程，条件必须是一个常量表达式
  using type = typename std::
      conditional_t<sizeof(T) <= kOnStackMax, Scoped<T>, OnHeap<T>>;
};