#include <initializer_list>
#include <string>

/**
 * STAR: 列表参数存在二义性时，
 *\*优先考虑 std::initializer_list 参数的函数
 */
template <typename T>
void f1(std::initializer_list<T>);

struct SWithNoexcept {
  int a;
  std::string s;
};
void f2(SWithNoexcept);

template <typename T, int N>
void f3(T(&&r)[N]);

void f4(int);

void g() {
  f1({1, 2, 3, 4});  // T 是 int，initializer_list 的大小是 4
  f2({1, "MKS"});    // f2(S{1, "MKS"})
  f3({1, 2, 3, 4});  // T 是 int，N 是 4
  f4({1});           // f4(int{1});
}