struct V {
  V(int i);
  // ...
};

struct A {
  A();  // 默认构造函数
  // ...
};

struct B : virtual V, virtual A {
  B() : V{1} {/*...*/};  // 默认构造函数，必须初始化基类 V
  // ...
};

class C : virtual V {
 public:
  C(int i) : V{i} {/*...*/};  // 必须初始化基类 V
  // ...
};

class D : virtual public B, virtual public C {
  // 从 B 和 C 隐式地获取虚基类 V
  // 从 B 隐式地获取虚基类 A
 public:
  D() {}  //\! C 和 V 没有默认构造函数

  D(int i) : C{i} {}  //\! V 没有默认构造函数

  D(int i, int j) : V{i}, C{j} {}  // OK
  // ...
};