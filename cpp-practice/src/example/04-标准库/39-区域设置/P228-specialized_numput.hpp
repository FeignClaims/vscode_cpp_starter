#include <cstddef>
#include <iostream>
#include <locale>
#include <string>

template <typename C>
class StringNumput
    : public std::num_put<C, typename std::basic_string<C>::iterator> {
 public:
  StringNumput()
      : std::num_put<C, typename std::basic_string<C>::iterator>{1} {}
};

void f(std::size_t i, std::string& s, int pos) {
  StringNumput<char> f;
  f.put(s.begin() + pos,
        std::cout,
        ' ',
        i);  // 格式化 i，存入 s；使用 cout 的格式规则
}