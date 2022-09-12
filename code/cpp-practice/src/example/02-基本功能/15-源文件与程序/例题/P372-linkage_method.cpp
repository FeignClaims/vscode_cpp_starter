#include <cstddef>

using FT = int (*)(const void*, const void*);  // FT 采用 C++ 链接

extern "C" {
using CFT = int (*)(const void*, const void*);  // CFT 采用 C 链接
void qsort(void* p, std::size_t n, std::size_t sz, CFT cmp);  // cmp 采用 C 链接
}

void isort(void* p,
           std::size_t n,
           std::size_t sz,
           FT cmp);  // cmp 采用 C++ 链接
void xsort(void* p, std::size_t n, std::size_t sz, CFT cmp);  // cmp 采用 C 链接
extern "C" void ysort(void* p,
                      std::size_t n,
                      std::size_t sz,
                      FT cmp);  // cmp 采用 C++ 链接

auto compare(const void*, const void*) -> int;  // compare() 采用 C++ 链接
extern "C" auto ccmp(const void*, const void*) -> int;  // ccmp() 采用 C 链接

void f(char* v, int sz) {
  qsort(v, sz, 1, &compare);  // 错误
  qsort(v, sz, 1, &ccmp);     // 正确

  isort(v, sz, 1, &compare);  // 正确
  isort(v, sz, 1, &ccmp);     // 错误
}

// 如果实现中 C 和 C++ 使用相同的调用规范，
// 则标记为错误的代码有可能被接受，被当作语言的扩展。