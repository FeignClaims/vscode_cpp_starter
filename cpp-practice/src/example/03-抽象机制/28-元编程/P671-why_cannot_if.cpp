#include <type_traits>

void f() {
  if (std::is_pod_v<int>) {
    using Type = int;  //\! 在 if 语句分支中只有声明
  } else {
    using Type = double;  //\! 退出作用域后，声明失效
  }
  Type a;
}

void g() {
  //\$ 不如类型函数 std::conditional 易读
  ((std::is_pod_v<int>) ? int{99} : double{99});
  std::conditional_t<std::is_pod_v<int>, int, double>(99);
}