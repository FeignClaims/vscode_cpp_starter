#include <iterator>

template <typename Iter>
void advance_helper(Iter p, int n, std::random_access_iterator_tag) {
  p += n;
}

template <typename Iter>
void advance_helper(Iter p, int n, std::forward_iterator_tag) {
  if (0 < n) {
    while (n--) ++p;
  } else if (n < 0) {
    while (n++) --p;
  }
}

template <typename Iter>
void advance(Iter p, int n) {  // 使用最优算法
  advance_helper(
      p, n, typename std::iterator_traits<Iter>::iterator_category{});
}