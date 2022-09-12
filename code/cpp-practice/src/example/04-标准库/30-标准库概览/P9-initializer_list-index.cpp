#include <initializer_list>
#include <iostream>

// star: std::initializer_list 没有提供下标运算符，可以对指针使用下标
void f(std::initializer_list<int> lst) {
  for (size_t i{}; i < lst.size(); ++i) {
    std::cout << lst[i] << '\n';  //\! 错误
  }

  const int* p{lst.begin()};
  for (size_t i{}; i < lst.size(); ++i) {
    std::cout << p[i] << '\n';
  }
}