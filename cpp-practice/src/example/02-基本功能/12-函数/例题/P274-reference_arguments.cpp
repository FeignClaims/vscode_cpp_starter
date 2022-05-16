auto fsqrt(const float&) -> float;  // Fortran 风格的 sqrt 接受一个引用参数
void update(float& i);

void g(double d) {
  float r{fsqrt(2.0f)};  // 传递存放 2.0f 的临时变量的引用
  r = fsqrt(r);          // 传递 r 的引用
  r = fsqrt(d);  // 传递存放 static_cast<float>(d) 的临时变量的引用
}

void g(double d, float r) {
  update(2.0f);  // alert: 常量实参
  update(r);     // 传递 r 的引用
  update(d);     // alert: 需要执行类型转换
}