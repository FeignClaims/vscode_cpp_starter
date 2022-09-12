#include <cstdint>

void f1(char);
void f1(long);

void f2(char*);
void f2(int*);

void j(int i) {
  f1(i);        // 二义性：f1(char) 还是 f1(long)?
  f2(nullptr);  // 二义性：f2(char*) 还是 f2(int*)?
}
//-------------------------------------------
void f3(char);
void f3(long);
inline void f3(int n) {
  f3(long(n));
}

void k(int i) {
  f3(i);  // STAR: 通过增加一个函数版本解决二义性问题
}