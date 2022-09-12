#include <iostream>
#include <type_traits>

class X {  // 输出 X
 public:
  void operator()(int x) { std::cout << "X" << x << "!"; }
  // ...
};

class Y {  // 输出 Y
 public:
  void operator()(int y) { std::cout << "Y" << y << "!"; }
  // ...
};

void f() {
  // alert: 如果 sizeof(int) > 4 外围没有括号，语法错误。
  //\! 因为编译器会将 > 解释为模板实参列表的结束标记。
  std::conditional_t<(sizeof(int) > 4), X, Y>{}(
      7);  // 创建一个 X 或一个 Y 并调用它

  using Z = std::conditional_t<std::is_polymorphic_v<X>,
                               X,
                               Y>;  // “记住”选出的函数对象类型
  Z zz;                             // 创建一个 X 或一个 Y
  zz(7);                            // 调用一个 X 或一个 Y
}