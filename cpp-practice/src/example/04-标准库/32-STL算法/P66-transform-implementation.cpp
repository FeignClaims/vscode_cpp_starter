#include <array>
#include <cctype>
#include <concepts>
#include <iterator>
#include <string>

template <std::input_iterator In,
          std::output_iterator<std::iter_value_t<In>> Out,
          std::invocable<std::iter_value_t<In>> Op>
auto transform(In first, In last, Out res, Op op) {
  while (first != last) {
    *res++ = op(*first++);
  }
  return res;
}