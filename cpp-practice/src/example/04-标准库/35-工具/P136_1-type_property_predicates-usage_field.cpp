#include <format>
#include <iostream>
#include <type_traits>

// star: 类型属性谓词所做的访问检查不依赖于它们的使用位置
//\* 即使用在成员和友元之外，也会一致地给出期望的结果
class X {
 public:
  auto operator=(const X&) = delete;

  ~X() = delete;

  static void inside();
};

void X::inside() {
  std::cout << std::format("inside =: \n", std::is_copy_assignable_v<X>);
  std::cout << std::format("inside ~:", std::is_destructible_v<X>);
}

void outside() {
  std::cout << std::format("inside =: \n", std::is_copy_assignable_v<X>);
  std::cout << std::format("inside ~:", std::is_destructible_v<X>);
}