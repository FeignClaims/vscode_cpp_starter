#include <iostream>
#include <stdexcept>

void printf(const char* s) {
  if (s == nullptr) return;

  while (*s) {
    if (*s == '%' &&
        *++s !=
            '%') {  // 确认没有更多的实参，在格式字符串中 %% 表示输出普通 % 字符
      throw std::runtime_error("invalid format: missing arguments");
    }
    std::cout << *s++;
  }
}

template <typename T, typename... Args>  // 可变参数模板列表：一个或多个参数
void printf(const char* s,
            T value,
            Args... args) {  // 函数参数列表：两个或多个参数
  while (s && *s) {
    if (*s == '%' && *++s != '%') {  // 一个格式说明符（忽略其具体是什么）
      std::cout << value;           // 使用一个非格式实参
      return printf(++s, args...);  // 用实参列表尾作为参数进行递进调用
    }
    std::cout << *s++;
  }
  throw std::runtime_error("extra arguments provided to printf");
}