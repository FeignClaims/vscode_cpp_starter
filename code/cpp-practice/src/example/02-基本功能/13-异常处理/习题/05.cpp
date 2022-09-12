#include <algorithm>
#include <memory>
#include <stdexcept>

template <typename T, typename A = std::allocator<T>>
struct VectorBase {
  VectorBase(const A& a, typename A::size_type n)
      : alloc{a}, elem{alloc.allocate(n)}, space{elem + n}, last{elem + n} {}
  VectorBase(const VectorBase&) = delete;
  VectorBase(VectorBase&& vb) noexcept
      : alloc{vb.alloc}, elem{vb.elem}, space{vb.space}, last{vb.last} {
    vb.elem = vb.space = vb.last = nullptr;
  }

  auto operator=(const VectorBase&) -> VectorBase& = delete;
  auto operator=(VectorBase&& vb) noexcept -> VectorBase& {
    std::swap(*this, vb);
    return *this;
  }

  ~VectorBase() { alloc.deallocate(elem, last - elem); }

  A alloc;
  T* elem;
  T* space;
  T* last;
};

template <typename T, typename A = std::allocator<T>>
class Vector {
 public:
  using size_type = unsigned int;

  explicit Vector(size_type, const T& = {}, const A& = {});
  Vector(const Vector&);
  Vector(Vector&&) noexcept;

  auto operator=(const Vector&) -> Vector&;
  auto operator=(Vector&&) noexcept -> Vector&;

  ~Vector() { destory_elements(); }

  [[nodiscard]] auto size() const -> size_type { return vb_.space - vb_.elem; }
  [[nodiscard]] auto capacity() const -> size_type {
    return vb_.last - vb_.elem;
  }

  auto operator[](size_type n) -> T& { return vb_.elem[n]; }
  auto at(size_type n) -> T& {
    if (n < 0 || n >= size()) throw std::out_of_range{"Out of range!"};
    return vb_.elem[n];
  }

  void reserve(size_type);
  void resize(size_type, const T& = {});
  void clear() { resize(0); }
  void push_back(const T&);

 private:
  void destory_elements();

  VectorBase<T, A> vb_;
};

template <typename T, typename A>
Vector<T, A>::Vector(size_type n, const T& t, const A& a) : vb_{a, n} {
  std::uninitialized_fill(vb_.elem, vb_.elem + n, t);
}

template <typename T, typename A>
Vector<T, A>::Vector(const Vector& v) : vb_{v.vb_.alloc, v.size()} {
  std::uninitialized_copy(v.begin(), v.end(), vb_.elem);
}

template <typename T, typename A>
Vector<T, A>::Vector(Vector&& v) noexcept : vb_{std::move(v.vb_)} {
}

template <typename T, typename A>
auto Vector<T, A>::operator=(const Vector& v) -> Vector& {
  if (capacity() < v.size()) {
    Vector temp{v};
    swap(*this, temp);
    return *this;
  }
  if (this == &v) return *this;

  size_type sz{size()};
  size_type asz{v.size()};
  vb_.alloc = v.vb_.alloc;
  if (asz <= sz) {
    std::copy(v.begin(), v.begin() + asz, vb_.elem);
    for (T* p{vb_.elem + asz}; p != vb_.space; ++p) {
      p->~T();
    }
  } else {
    std::copy(v.begin(), v.begin() + sz, vb_.elem);
    std::uninitialized_copy(v.begin() + sz, v.end(), vb_.space);
  }
  vb_.space = vb_.elem + asz;
  return *this;
}

template <typename T, typename A>
auto Vector<T, A>::operator=(Vector&& v) noexcept -> Vector& {
  clear();
  swap(*this, v);
}

template <typename T, typename A>
void Vector<T, A>::reserve(size_type newalloc) {
  if (newalloc <= capacity()) return;
  VectorBase<T, A> b{vb_.alloc, newalloc};
  std::uninitialized_move(vb_.elem, vb_.elme + size(), b.elem);
  std::swap(vb_, b);
}

template <typename T, typename A>
void Vector<T, A>::resize(size_type newsize, const T& val) {
  reserve(newsize);
  if (size() < newsize) {
    std::uninitialized_fill(vb_.elem + size(), vb_.elem + newsize, val);
  } else {
    std::destroy(vb_.elem + newsize, vb_.elem + size());
  }
  vb_.space = vb_.last = vb_.elem + newsize;
}

template <typename T, typename A>
void Vector<T, A>::push_back(const T& val) {
  if (capacity() == size()) {
    reserve(size() ? 2 * size() : 8);
  }
  vb_.alloc.construct(&vb_.elem[size()], val);
  ++vb_.space;
}

template <typename T, typename A>
void Vector<T, A>::destory_elements() {
  for (T* p{vb_.elem}; p != vb_.space; ++p) {
    p->~T();
  }
  vb_.space = vb_.elem;
}