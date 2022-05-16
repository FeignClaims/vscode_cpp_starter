using P1 = int (*)(int*);
using P2 = void (*)(void);

void f(P1 pf) {
  P2 pf2{reinterpret_cast<P2>(pf)};
  pf2();                              // alert: 可能发生严重错误
  P1 pf1{reinterpret_cast<P1>(pf2)};  // 把 pf2“转换回来”
  int x{7};
  int y{pf1(&x)};  // note:
  // ...
}