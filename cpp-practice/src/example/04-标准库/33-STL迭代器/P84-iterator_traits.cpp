#include <iterator>
template <typename Iter>
auto read(Iter p, int n) -> typename Iter::value_type {  // 不是通用的
  // ...进行一些检查...
  return p[n];
}

template <typename Iter>
auto read(Iter p, int n) ->
    typename std::iterator_traits<Iter>::value_type {  // 更通用
  // ...进行一些检查...
  return p[n];
}