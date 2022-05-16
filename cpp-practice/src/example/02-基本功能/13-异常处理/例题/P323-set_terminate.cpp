#include <exception>

using terminate_handler = void (*)();  // 源于 <exception>

[[noreturn]] void my_handler() {  // 终止处理程序无法返回任何值
  // 自行处理终止
}

void dangerous() {  // 非常危险！
  terminate_handler old{std::set_terminate(my_handler)};
  // ...
  std::set_terminate(old);  // 修复旧的终止处理程序
}