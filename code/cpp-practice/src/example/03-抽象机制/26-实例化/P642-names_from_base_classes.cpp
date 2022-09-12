void g(int);
void g2(int);

struct B {
  using Type = int;
  void g(char);
  void g2(char);
};

template <typename T>
class X : public T {
 public:
  typename T::Type m;
  Type m2;  //\! Type 不在作用域中

  // STAR: 使用依赖性类的名字：①用 using 声明将名字引入作用域
  using T::g2();  // 将 T::g2() 引入作用域

  void f() {
    // STAR: 使用依赖性类的名字：②声明一个名字指向此类的一个对象
    this->g(2);  // 调用 T::g
    // STAR: 使用依赖性类的名字：③用依赖性类型限定名字
    T::g(2);
    g(2);   // 调用 ::g(int)；是否出乎意料？
    g2(2);  // 调用 T::g2
  }
  // ...
};

void h(X<B> x) {
  x.f();
}