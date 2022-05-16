template <typename T, typename In>
void destroy(In b, In e) {
  for (; b != e; ++b) {  // 销毁 [b:e)
    b->~T();
  }
}