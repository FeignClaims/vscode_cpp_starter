#include <utility>

class Matrix {
 public:
  auto operator[](std::pair<int, int>) -> int;
};

auto f(double d, Matrix& m) {
  int v{7};            // 初始化器（直接初始化）
  int v2 = {7};        // 初始化器（拷贝初始化）
  int v3 = m[{2, 3}];  // 假设 m 接受一个值对作为其下标

  v = {8};       // 赋值运算的右侧运算对象
  v += {88};     // 赋值运算的右侧运算对象
  {v} = 9;       // alert: 不能作为赋值运算的左侧运算对象
  v = 7 + {10};  // alert: 不能作为非赋值运算符的运算对象
  f({10.0});     // 函数实参
  return {11};   // 返回值
}