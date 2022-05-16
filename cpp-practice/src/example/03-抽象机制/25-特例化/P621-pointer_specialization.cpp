template <typename T>
class Vector {  // 通用向量类型
 public:
  Vector();
  explicit Vector(int);

  auto elem(int i) -> T& { return v_[i]; }
  auto operator[](int i) -> T&;

  void swap(Vector&);
  // ...

 private:
  T* v_;
  int sz_;
};

template <>
class Vector<void*> {  // 完整特例化
 public:
  Vector();
  explicit Vector(int);

  auto elem(int i) -> void*;
  auto operator[](int i) -> void*;

 private:
  void** p;
};

template <typename T>
class Vector<T*> : private Vector<void*> {  // 部分特例化
 public:
  using Base = Vector<void*>;

  Vector() {}
  explicit Vector(int i) : Base(i) {}

  auto elem(int i) -> T*& { return reinterpret_cast<T*&>(Base::elem(i)); }
  auto operator[](int i) -> T*& {
    return reinterpret_cast<T*&>(Base::operator[](i));
  }

  // ...
};