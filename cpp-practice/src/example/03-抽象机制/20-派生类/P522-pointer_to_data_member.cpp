#include <iostream>

struct C {
  explicit C(const char* v) : val(v) {}

  void print(int x) { std::cout << val << x << '\n'; }
  auto f1(int) -> int;
  void f2();

  const char* val;
  int i{};
};

using Pmfi = void (C::*)(int);  // C 的成员函数指针，接收 int
using Pm = const char* C::*;    // C 的 char* 数据成员的指针

void f(C& z1, C& z2) {
  C* p{&z2};
  Pmfi pf{&C::print};
  Pm pm{&C::val};

  z1.print(1);
  (z1.*pf)(2);
  z1.*pm = "nv1 ";
  p->*pm = "nv2 ";
  z2.print(3);
  (p->*pf)(4);

  pf = &C::f1;  //\! 返回类型不匹配
  pf = &C::f2;  //\! 参数类型不匹配
  pm = &C::i;   //\! 类型不匹配
  pm = pf;      //\! 类型不匹配
}