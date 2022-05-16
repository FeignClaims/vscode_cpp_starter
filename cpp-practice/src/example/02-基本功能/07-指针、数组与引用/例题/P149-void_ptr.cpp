#include <iostream>

void f(int* pi) {
  void* pv{pi};  // ok: 发生了从 int* 到 void* 的隐式类型转换
  /**
  *pv;  // alert: 不允许解引用 void*
  ++pv; // alert: 不允许对 void* 执行递增操作（所指的对象尺寸未知）
  */

  int* pi2{static_cast<int*>(pv)};  // 显式转换回 int*;

  /**
  double* pd1{pv};  // 错误
  double* pd2{pi};  // 错误
  */
  double* pd3{static_cast<double*>(pv)};  // 不安全
}