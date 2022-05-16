#include <new>

// STAR: 不进行异常处理的 new 和 delete
void f(int n) {
  int* p{new (std::nothrow) int[n]};  // 在自由存储上分配 n 个 int
  if (p == nullptr) {                 // 无可用内存
    // ...处理分配内存错误...
  }
  // ...
  operator delete(p, std::nothrow);  // 释放 *p;
}