#include <iterator>

template <std::input_iterator In, std::input_iterator In2>
auto lexicographical_compare(In first, In last, In2 first2, In2 last2) {
  for (; first != last && first2 != last2; ++first, ++last) {
    if (*first < *first2) return true;   // [first:last) < [first2:last2)
    if (*first2 < *first) return false;  // [first2:last2) < [first:last)
  }
  return first == last &&
         first2 !=
             last2;  // 若 [first:last) 更短，[first:last) < [first2:last2)
}