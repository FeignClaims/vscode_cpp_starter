#include "P331-vector_6.hpp"

#include <type_traits>

template <typename T, typename A>
void safe_assign1(Vector<T, A>& a, const Vector<T, A>& b) {  // 简单的 a = b
  Vector<T, A> temp{a};  // 把元素拷贝给临时量
  std::swap(a, temp);
}

template <typename T, typename A>
void safe_assign2(Vector<T, A>& a,
                  const Vector<T, A> b) {  // 简单的 a = b（注意：b 是值传递的）
  std::swap(a, b);
}