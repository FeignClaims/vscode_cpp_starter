#include <memory>
template <typename T, typename A = std::allocator<T>>
class Vector {
 public:
  using size_type = unsigned int;  // 表示 vector 尺寸的数据类型
  using iterator_type = T*;

  explicit Vector(size_type n, const T& val = {}, const A& = {});
  Vector(const Vector& a);      // 拷贝构造函数
  Vector(Vector&& a) noexcept;  // 移动构造函数

  auto operator=(const Vector& a) -> Vector&;  // 拷贝赋值运算
  auto operator=(Vector&& a) -> Vector&;       // 移动赋值

  ~Vector();

  [[nodiscard]] auto size() const -> size_type { return space_ - elem_; }
  [[nodiscard]] auto capacity() const -> size_type { return last_ - elem_; }
  void reserve(size_type n);  // 增加容量到 n

  void resize(size_type n, const T& = {});  // 改变 n 的大小
  void push_back(const T&);                 // 在末尾增加元素

 private:
  T* elem_;   // 分配空间的开始
  T* space_;  // 元素序列末尾，可扩展空间的开始
  T* last_;   // 分配空间的末尾
  A alloc_;   // 分配器
};

// note: 构造函数第二版
template <typename T, typename A>
Vector<T, A>::Vector(size_type n, const T& val, const A& a)  // 详细说明
    : alloc_{a}                                              // 拷贝分配器
{
  elem_ = alloc_.allocate(n);  // 分配元素的空间
  iterator_type p{};
  try {
    iterator_type end = elem_ + n;
    for (p = elem_; p != end; ++p) {
      alloc_.construct(p, val);  // 构造元素（见 34.4 节）
    }
    last_ = space_ = p;
  } catch (...) {
    for (iterator_type q{elem_}; q != p; ++q) {
      alloc_.destroy(q);  // 销毁已构造的元素
    }
    alloc_.deallocate(elem_, n);  // 释放内存
    throw;                        // 重新抛出
  }
}