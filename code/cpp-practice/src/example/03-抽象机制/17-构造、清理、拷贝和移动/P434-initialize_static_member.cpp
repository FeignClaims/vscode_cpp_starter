#include <cmath>

class Curious {
 public:
 private:
  static const int c1{7};  // 正确
  static int c2{11};       //\! 非 const
  const int c3{13};        // 正确，但非 static（见 17.4.4 节）
  static const int c4 = std::sqrt(9);  //\! 类内初始化器不是常量
  static const float c5 =
      7.0;  //\! 类内初始化成员不是整型（应使用 constexpr 而非 const）
  // ...
};