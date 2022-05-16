struct B1 {
  void f(int);
};

struct B2 {
  void f(double);
};

struct D : B1, B2 {
  // STAR: 通过 using 声明引入基类成员（函数重载，构造函数）
  using B1::f;
  using B2::f;
  void f(char);
};

void use(D d) {
  d.f(1);    // 调用 D::f(int)，即 B1::f(int)
  d.f('a');  // 调用 D::f(char)
  d.f(1.0);  // 调用 D::f(double)，即 B2::f(double)
}