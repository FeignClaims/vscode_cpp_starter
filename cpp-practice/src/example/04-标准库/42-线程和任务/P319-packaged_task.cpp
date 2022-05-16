#include <exception>
#include <format>
#include <future>
#include <iostream>
#include <stdexcept>

auto ff(int i) -> int {
  if (i != 0) return i;
  throw std::runtime_error("ff(0)");
}

auto main() -> int {
  std::packaged_task<int(int)> pt1{ff};  // 将 ff 保存在 pt1 中
  std::packaged_task<int(int)> pt2{ff};  // 将 ff 保存在 pt2

  pt1(1);  // 令 pt1 调用 ff(1);
  pt2(0);  // 令 pt2 调用 ff(0);

  auto v1 = pt1.get_future();
  auto v2 = pt2.get_future();

  try {
    std::cout << std::format("{}\n", v1.get());  // 打印
    std::cout << std::format("{}\n", v2.get());  // 打印
  } catch (std::exception& e) {
    std::cout << std::format("exception: {}\n", e.what());
  }
}