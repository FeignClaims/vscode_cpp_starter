struct SWithNoexcept {
  int a;
  int b;
};

struct SS {
  double a;
  double b;
};

void f(SWithNoexcept);  // f() 接受一个 S

void g(SWithNoexcept);
void g(SS);  // 重载了 g()

void h() {
  f({1, 2});  // note: 调用 f(S{1, 2})

  g({1, 2});               // alert: 存在二义性
  g(SWithNoexcept{1, 2});  // note: 调用 g(S)
  g(SS{1, 2});             // note: 调用 g(SS)
}