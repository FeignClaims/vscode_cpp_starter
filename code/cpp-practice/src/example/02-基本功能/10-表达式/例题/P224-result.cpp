void f(int x, int y) {
  int j = x = y;  // x = y 的值是 x 在执行赋值运算之后的结果值
  int* p = &++x;  // p 指向 x
  int* q = &(x++);  // alert: x++ 不是一个左值（它不是存储在 x 中的值）
  int* p2 = &(x > y ? x : y);  // 具有较大值的 int 的地址
  int& r = (x < y) ? x : 1;    // alert: 1 不是左值
}

// x++ 的实现：
auto post_plus(int x) -> int {
  int temp{x};
  x = x + 1;
  return temp;
}