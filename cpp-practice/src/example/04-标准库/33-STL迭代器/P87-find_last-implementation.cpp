#include <ranges>

template <std::ranges::range C>
auto find_last(C& c, std::ranges::range_value_t<C> v)
    -> std::ranges::iterator_t<C> {  // C::reverse_iterator 和 C::iterator
                                     // 是不同类型
  auto ri = find(std::ranges::rbegin(c), std::ranges::rend(c), v);
  if (ri == std::ranges::rend(c))
    return std::ranges::end(c);  // 用 c.end() 表示“未找到”
  return std::ranges::prev(
      ri.base());  // ri.base() 返回对应的 iterator，指向 ri 之后的位置
}