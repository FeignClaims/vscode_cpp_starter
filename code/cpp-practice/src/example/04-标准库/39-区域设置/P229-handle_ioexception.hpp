#include <ios>
#include <ostream>
template <typename C, typename Tr>
void handle_ioexception(std::basic_ostream<C, Tr>& s) {  // 从 catch 子句调用
  if (s.exceptions() & std::ios_base::badbit) {
    try {
      s.setstate(std::ios_base::badbit);  // 可能抛出 std::basic_ios::failure
    } catch (...) {
      // ... do nothing ...
    }
    throw;  // 重抛出
  }
  s.setstate(std::ios_base::badbit);
}