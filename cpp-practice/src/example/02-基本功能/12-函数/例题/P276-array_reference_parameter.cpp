void f1(int (&r)[4]);

void g1() {
  int a1[]{1, 2, 3, 4};
  int a2[]{1, 2};

  f(a1);  // OK
  f(a2);  // alert: 元素个数有误
}
//------------------------------------------
template <typename T, int N>
void f2(T (&r)[N]) {
  // ...
}

int a1[10];
double a2[100];

void g2() {
  f2(a1);  // T 是 int；N 是 10
  f2(a2);  // T 是 double；N 是 100
}