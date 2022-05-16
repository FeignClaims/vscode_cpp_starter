template <typename T>
class MatrixBase {  // 矩阵所用内存，对所有元素的操作
 public:
  // ...
  [[nodiscard]] auto size() const -> int { return sz; }

 protected:
  int sz;   // 元素数量
  T* elem;  // 矩阵元素
};

template <typename T, int N>
class Matrix : public MatrixBase<T> {  // N 维矩阵
  // ...
  auto data() -> T* {   // 返回指向元素存储空间的指针
    return this->elem;  //\* 必须使用 this-> 限定
  }
};