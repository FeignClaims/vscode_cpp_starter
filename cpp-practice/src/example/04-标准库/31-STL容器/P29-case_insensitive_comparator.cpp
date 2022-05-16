#include <cctype>
#include <string>

struct Nocase {  // 大小写不敏感的字符串比较
  auto operator()(const std::string&, const std::string&) const -> bool;
};

auto Nocase::operator()(const std::string& x, const std::string& y) const
    -> bool {
  // 若 x 字典序上小于 y，则返回 true，不考虑大小写
  auto p = x.begin();
  auto q = y.begin();

  while (p != x.end() && q != y.end() && std::toupper(*p) == toupper(*q)) {
    ++p;
    ++q;
  }
  if (p == x.end()) return q != y.end();
  if (q == y.end()) return false;
  return std::toupper(*p) < std::toupper(*q);
}