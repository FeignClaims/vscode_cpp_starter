#include <algorithm>
#include <string>

auto main() -> int {
  std::string s{"herewego"};
  std::make_heap(s.begin(), s.end());
  std::pop_heap(s.begin(), s.end());
  std::pop_heap(s.begin(), s.end() - 1);
  std::pop_heap(s.begin(), s.end() - 2);

  *(s.end() - 3) = 'f';
  std::push_heap(s.begin(), s.end() - 2);
  *(s.end() - 2) = 'x';
  std::push_heap(s.begin(), s.end() - 1);
  *(s.end() - 1) = 'y';
  std::push_heap(s.begin(), s.end());
  std::sort_heap(s.begin(), s.end());
  std::reverse(s.begin(), s.end());
}