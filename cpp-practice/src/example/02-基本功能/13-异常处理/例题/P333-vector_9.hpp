#include <algorithm>
#include <memory>
#include <utility>

template <typename T, typename A = std::allocator<T>>
struct VectorBase {
  VectorBase(const A& a, typename A::size_type n)
      : alloc{a}, elem{alloc.allocate(n)}, space{elem + n}, last{elem + n} {}
  VectorBase(const VectorBase&) = delete;  // 无拷贝操作
  VectorBase(VectorBase&&) noexcept;       // 移动操作

  auto operator=(const VectorBase&) -> VectorBase& = delete;
  auto operator=(VectorBase&&) noexcept -> VectorBase&;

  ~VectorBase() { alloc.deallocate(elem, last - elem); }

  A alloc;   // 分配器
  T* elem;   // 分配空间的开始
  T* space;  // 元素序列的末尾，可扩展空间的开始
  T* last;   // 已分配空间的末尾
};

template <typename T, typename A>
VectorBase<T, A>::VectorBase(VectorBase&& a) noexcept
    : alloc{a.alloc}, elem{a.elem}, space{a.space}, last{a.space} {
  a.elem = a.space = a.last = nullptr;  // 不再拥有任何内存
}

template <typename T, typename A>
auto VectorBase<T, A>::operator=(VectorBase&& a) noexcept -> VectorBase& {
  swap(*this, a);
  return *this;
}

template <typename T, typename A = std::allocator<T>>
class Vector {
 public:
  using size_type = unsigned int;

  explicit Vector(size_type n, const T& val = {}, const A& a = {});
  Vector(const Vector& a);      // 拷贝构造函数
  Vector(Vector&& a) noexcept;  // 移动构造函数

  auto operator=(const Vector& a) -> Vector&;      // 移动赋值运算
  auto operator=(Vector&& a) noexcept -> Vector&;  // 移动赋值运算

  ~Vector() { destroy_elements(); }

  [[nodiscard]] auto size() const -> size_type { return vb_.space - vb_.elem; }
  [[nodiscard]] auto capacity() const -> size_type {
    return vb_.last - vb_.elem;
  }

  void reserve(size_type);  // 增加存储容量

  void resize(size_type, const T& = {});  // 改变元素个数
  void clear() { resize(0); }             // 清空 vector
  void push_back(const T&);               // 在末尾添加一个元素
 private:
  void destroy_elements();

  VectorBase<T, A> vb_;  // 此处为数据
};

template <typename T, typename A>
Vector<T, A>::Vector(size_type n, const T& val, const A& a) : vb_{a, n} {
  std::uninitialized_fill(vb_.elem, vb_.elem + n, val);
}

template <typename T, typename A>
Vector<T, A>::Vector(const Vector& a) : vb_{a.vb_.alloc, a.size()} {
  std::uninitialized_copy(a.begin(), a.end(), vb_.elem);
}

template <typename T, typename A>
Vector<T, A>::Vector(Vector&& a) noexcept : vb_{std::move(a.vb_)} {
}

template <typename T, typename A>
auto Vector<T, A>::operator=(const Vector& a) -> Vector& {
  if (capacity() < a.size()) {  // 分配新的 vector 内容
    Vector temp{a};             // 拷贝分配器
    swap(*this, temp);          // 交换内容
    return *this;               // 隐式地销毁旧值
  }
  if (this == &a) return *this;  // 优化自赋值

  size_type sz{size()};
  size_type asz{a.size()};
  vb_.alloc = a.vb_.alloc;  // 拷贝分配器
  if (asz <= sz) {
    std::copy(a.begin(), a.begin() + asz, vb_.elem);
    for (T* p{vb_.elem + asz}; p != vb_.space;
         ++p) {  // 销毁多余的元素（见 16.2.6 节）
      p->~T();
    }
  } else {
    std::copy(a.begin(), a.begin() + sz, vb_.elem);
    std::uninitialized_copy(a.begin() + sz,
                            a.end(),
                            vb_.space);  // 构造额外的元素
  }
  vb_.space = vb_.elem + asz;
  return *this;
}

template <typename T, typename A>
auto Vector<T, A>::operator=(Vector&& a) noexcept -> Vector& {
  clear();         // 销毁元素
  swap(*this, a);  // 转移所有权
}

template <typename T, typename A>
void Vector<T, A>::reserve(size_type newalloc) {
  if (newalloc <= capacity()) return;       // 无法减少空间分配
  VectorBase<T, A> b{vb_.alloc, newalloc};  // 获取新空间
  std::uninitialized_move(vb_.elem, vb_.elem + size(), b.elem);  // 移动元素
  std::swap(vb_, b);                                             // 存入新值
}  // 隐式地释放旧值

// note: resize
template <typename T, typename A>
void Vector<T, A>::resize(size_type newsize, const T& val) {
  reserve(newsize);
  if (size() < newsize) {
    std::uninitialized_fill(vb_.elem + size(),
                            vb_.elem + newsize,
                            val);  // 构造新元素
  } else {
    std::destroy(vb_.elem + newsize, vb_.elem + size());  // 销毁多余元素
  }
  vb_.space = vb_.last = vb_.elem + newsize;
}

template <typename T, typename A>
void Vector<T, A>::destroy_elements() {
  for (T* p{vb_.elem}; p != vb_.space; ++p) {
    p->~T();  // 销毁元素（见 17.2.4 节）
  }
  vb_.space = vb_.elem;
}