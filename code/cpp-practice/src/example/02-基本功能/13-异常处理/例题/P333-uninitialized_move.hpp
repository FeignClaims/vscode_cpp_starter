#include <utility>
template <typename T, typename In, typename Out>
auto uninitialized_move(In b, In e, Out oo) -> Out {
  for (; b != e; ++b, ++oo) {
    new (static_cast<void*>(&*oo)) T{std::move(*b)};  // 移动构造
    b->~T();                                          // 销毁
  }
  return b;
}