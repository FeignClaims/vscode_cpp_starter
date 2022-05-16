struct B {
  void b();
  void c();
};

// STAR: using 声明与私有/保护派生组合，获取基类部分接口
class BB : private B {  // 提供对 B::b 和 B::c 的访问权，但未提供 B::a 的访问权
 public:
  using B::b;
  using B::c;
};