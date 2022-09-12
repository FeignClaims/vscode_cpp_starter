#include <ios>
#include <ostream>

struct smanip {
  smanip(auto (*ff)(std::ios_base&, int)->std::ios_base&, int ii)
      : f{ff}, i{ii} {}

  auto (*f)(std::ios_base&, int) -> std::ios_base&;  // 调用的函数
  int i;                                             // 使用的值
};

template <typename C, typename Tr>
auto operator<<(std::basic_ostream<C, Tr>& os, const smanip& m)
    -> std::basic_ostream<C, Tr>& {
  m.f(os, m.i);  // 用 m 保存的值调用 m 的 f
  return os;
}

inline auto setprecision(int n) -> smanip {
  auto h = [](std::ios_base& s, int x) -> std::ios_base& {
    s.precision(x);
    return s;
  };
  return smanip(h, n);  // 创建函数对象
}