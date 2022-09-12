#include <string>
void f(int i) {
  switch (i) {
    case 0:
      int x{};   // 未初始化
      int y{3};  // alert: 程序有可能跳过该声明（显式初始化）
      std::string s;  // alert: 程序有可能跳过该声明（隐式初始化）
    case 1:
      ++x;  // 错误，试图使用未初始化的对象
      ++y;
      s = "nasty!";
  }
}