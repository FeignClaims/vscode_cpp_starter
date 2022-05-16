#include <cstdarg>
#include <iostream>

void error(int severity...) {  // “severity” 之后紧跟一个以 0 结尾的字符串列表
  std::va_list ap{};
  va_start(ap, severity);  // arg 启动

  while (true) {
    char* p{va_arg(ap, char*)};
    if (!p) break;
    std::cerr << p << ' ';
  }

  va_end(ap);  // arg 结束

  std::cerr << '\n';
  if (severity) exit(severity);
}