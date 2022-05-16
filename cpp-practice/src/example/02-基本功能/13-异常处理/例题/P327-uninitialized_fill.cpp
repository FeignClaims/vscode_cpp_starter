template <typename For, typename T>
void uninitialized_fill(For beg, For end, const T& x) {
  For p;
  try {
    for (p = beg; p != end; ++p) {
      ::new (static_cast<void*>(&*p))
          T{x};  // 在 *p 中构造 x 的拷贝（见 11.2.4 节）
    }
  } catch (...) {
    for (For q = beg; q != p; ++q) {
      (&*q)->~T();  // 销毁元素（见 11.2.4 节）
      throw;        // 重新抛出（见 13.5.2.1 节）
    }
  }
}