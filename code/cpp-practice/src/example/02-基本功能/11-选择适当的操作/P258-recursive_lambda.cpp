#include <functional>
#include <string>

void f(std::string& s1, std::string& s2) {
  /**
   *STAR: lamda 使用递归
   *\*我们无法在推断出一个 auto 变量的类型之前使用它
   *\*所以必须通过 std::function<RE(ARG)> 指定类型
   **/
  std::function<void(char*, char*)> rev = [&](char* b, char* e) {
    if (1 < e - b) {
      std::swap(*b, *--e);
      rev(++b, e);
    }
  };
  rev(&s1[0], &s1[0] + s1.size());
  rev(&s2[0], &s2[0] + s2.size());
}