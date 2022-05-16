#include <iostream>
struct Poly {  // 多态基类
  virtual void f();
  // ...
};

struct NonPoly {};  // 无虚函数

struct D1 : Poly {};

struct D2 : NonPoly {};

void f(NonPoly& npr, Poly& pr) {
  std::cout << typeid(npr).name() << '\n';  // 打印类似 "NonPoly" 的内容
  std::cout << typeid(pr).name() << '\n';  // 打印 Poly 或 Poly 派生类的名字
}

void g() {
  D1 d1;
  D2 d2;
  f(d2, d1);  // 打印 "NonPoly D1"
  f(*static_cast<NonPoly*>(nullptr), *static_cast<Poly*>(nullptr));  //\! 糟糕！
}