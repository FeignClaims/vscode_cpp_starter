enum class Flag1 : char { x = 1, y = 2, z = 4, e = 8 };
enum Flag2 : char { x = 1, y = 2, z = 4, e = 8 };  // 范围：[0: 15]

auto main() -> int {
  Flag1 f10{};    // f0 的默认值是 0
  Flag1 f11 = 5;  // alert: 5 不属于 Flag1 类型
  Flag1 f12{5};   // alert: 不允许窄化转换成 enum class 类型
  Flag1 f13{static_cast<Flag1>(5)};  // “不近人情”的转换
  Flag1 f14{static_cast<Flag1>(
      999)};  // “错误”：999 不是一个 char 类型的值（也许根本捕获不到）

  Flag2 f20{};    // f0 的默认值是 0
  Flag2 f21 = 5;  // alert: 5 不属于 Flag2 类型
  Flag2 f22{5};   // alert: 不存在 int 向 Flag 的显式类型转换
  Flag2 f23{static_cast<Flag1>(5)};  // note: 5 在 Flag 的取值范围之内
  Flag2 f24{static_cast<Flag1>(
      z | e)};  // note: 12 在 Flag 的取值范围之内；不需要专门定义运算符|
  Flag2 f25{
      static_cast<Flag1>(999)};  // “未定义的”：999 不是在 Flag 的取值范围之内
}