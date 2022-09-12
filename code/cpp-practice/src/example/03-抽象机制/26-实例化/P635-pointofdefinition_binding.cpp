void g(double);
void g2(double);

template <typename T>
auto ff(T a) -> int {
  g2(2);  // 调用 g2(double);
  g3(2);  //\! 作用域中没有 g3()
  g(2);   // 调用 g(double)；g(int) 不在作用域中
  // ...
}

void g(int);
void g3(int);

int x = ff(5);