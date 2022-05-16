#include <functional>
#include <iterator>

template <std::input_iterator In,
          std::output_iterator<std::iter_value_t<In>> Out,
          typename BinOp>
auto partial_sum(In first, In last, Out res, BinOp op) {
  if (first == last) return res;
  *res = *first;
  auto val = *first;
  while (++first != last) {
    val = op(val, *first);
    *++res = val;
  }
  return ++res;
}

template <std::input_iterator In,
          std::output_iterator<std::iter_value_t<In>> Out>
auto partial_sum(In first, In last, Out res) {
  return partial_sum(first, last, res, std::plus{});
}