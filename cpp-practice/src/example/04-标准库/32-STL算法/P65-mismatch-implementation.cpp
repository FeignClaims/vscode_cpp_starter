#include <concepts>
#include <functional>
#include <iterator>
#include <utility>

template <std::input_iterator In, std::input_iterator In2>
auto mismatch(In first,
              In last,
              In2 first2,
              std::predicate auto p = std::equal_to<std::iter_value_t<In>>{})
    -> std::pair<In, In2> {
  while (first != last && p(*first, *first2)) {
    ++first;
    ++first2;
  }
  return {first, first2};
}