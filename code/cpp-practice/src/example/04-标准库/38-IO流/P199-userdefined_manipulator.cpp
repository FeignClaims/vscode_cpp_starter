// STAR: 用户自定义操纵符
//\* 按预定义的模式输出一个浮点数，同时不影响未来的输出操作
#include <ios>
#include <iostream>
#include <ostream>
#include <sstream>
class Form;  // 我们的格式化类型

struct BoundForm {  // 格式与值
  const Form& f;
  double val;
};

class Form {
 public:
  explicit Form(int precision = 6,
                std::ios_base::fmtflags fmtflags = 0,
                int width = 0)
      : precision_{precision}, fmtflags_{fmtflags}, width_{width} {}

  auto operator()(double d) const
      -> BoundForm {  // 为 *this 和 d 创建一个 BoundForm
    return BoundForm{*this, d};
  }

  auto scientific() -> Form& {
    fmtflags_ = std::ios_base::scientific;
    return *this;
  }
  auto fixed() -> Form& {
    fmtflags_ = std::ios_base::fixed;
    return *this;
  }
  auto general() -> Form& {
    fmtflags_ = 0;
    return *this;
  }

  auto uppercase() -> Form&;
  auto lowercase() -> Form&;
  auto precision(int precision) -> Form& {
    precision_ = precision;
    return *this;
  }
  auto width(int width) -> Form& {
    width_ = width;
    return *this;
  }
  auto plus(bool b = true) -> Form&;            // 显式加号
  auto trailing_zeros(bool b = true) -> Form&;  // 打印尾置

 private:
  friend auto operator<<(std::ostream& /*os*/, const BoundForm& /*bf*/)
      -> std::ostream&;

  int precision_;                     // 精度
  std::ios_base::fmtflags fmtflags_;  // 一般、科学计数法或定点2
  int width_;                         // 宽度 0 表示“按需分配宽度”
  // ...
};

// star: 这些声明令 << 和 () 的组合变成一个三元运算符
auto operator<<(std::ostream& os, const BoundForm& bf) -> std::ostream& {
  std::ostringstream s;
  s.precision(bf.f.precision_);
  s.setf(bf.f.fmtflags_, std::ios_base::floatfield);
  s << bf.val;           // 生成字符串保存在 s 中
  return os << s.str();  // 将 s 输出到 os
}

const Form gen4{4};  // 一般格式，精度 4

void f(double d) {
  Form sci8;
  sci8.scientific().precision(8);  // 科学计数法格式，精度 8
  std::cout << d << ' ' << gen4(d) << ' ' << sci8(d) << ' ' << d << '\n';

  Form sci{10, std::ios_base::scientific};  // 科学计数法格式，精度 10
  std::cout << d << ' ' << gen4(d) << ' ' << sci(d) << ' ' << d << '\n';
}

auto main() -> int {
  f(1234.56789);
}