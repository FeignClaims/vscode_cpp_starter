// STAR: 友元性生效的范围
class C1 {};  // 将成为 N::C 的友元
void f1();    // 将成为 N::C 的友元

namespace N {
class C2 {};  // 将成为 C 的友元
void f2() {
}  // 将成为 C 的友元

class C {
 public:
  friend class C1;  // OK（已经预先定义）
  friend void f1();
  friend class C2;  // OK（已经预先定义）
  friend void f2();

  friend class C3;  // OK（已经在外层作用域中定义）
  friend void f3();
  friend class C4;  // 首次声明出现在名字空间 N 内，因此友元关系只存在于此
  friend void f4();

 private:
  int x{};
};
class C3 {};  // C 的友元
void f3() {   // OK: C 的友元
  C x;
  x.x = 1;
}
}  // namespace N
class C4 {};  // 不是 N::C 的友元
void f4() {   //\! 错误：x 是私有的并且 f4() 不是 N::C 的友元
  N::C x;
  x.x = 1;
}