#include <cstddef>

template <std::size_t N, std::size_t A>
struct aligned_storage {
  using type = struct {
    alignas(A) unsigned char data[N];
  };  // N 个对齐到 A 的 char
};