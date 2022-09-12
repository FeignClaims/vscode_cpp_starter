#include <format>
#include <functional>
#include <iostream>

void incr(int& i) {
  ++i;
}

void user1() {
  int i{1};
  incr(i);  // i 变为 2
  auto inc = std::bind(incr, std::placeholders::_1);
  inc(i);  // i 仍为 2；inc(i) 递增的是 i 的局部拷贝
  std::cout << std::format("user1: {}\n", i);
}

void user2() {
  int i{1};
  incr(i);  // i 变为 2
  auto inc = [](auto&& placeholder1) {
    return incr(std::forward<decltype(placeholder1)>(placeholder1));
  };       //\* 用 lambda 替代 std::bind，并完美转发
  inc(i);  // i 变为 3
  std::cout << std::format("user2: {}\n", i);
}

auto main() -> int {
  user1();
  user2();
}