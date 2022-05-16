void g(int);

template <typename T>
void by_value(T a) {
  g(a);  // g 在实例化点绑定
}

void h(int i) {
  extern void g(double);
  by_value(i);  // 调用的是 g(int) 而非 g(double)
}
//\* f<int> 的实例化点