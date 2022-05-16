#include <chrono>
#include <condition_variable>
#include <format>
#include <iostream>
#include <mutex>
#include <thread>

void simple_timer(int delay) {
  std::condition_variable timer;
  std::mutex mtx;  // 保护 timer 的互斥量
  auto t0 = std::chrono::steady_clock::now();
  std::unique_lock<std::mutex> lck{mtx};                  // 获取 mtx
  timer.wait_for(lck, std::chrono::milliseconds{delay});  // 释放和获取 mtx
  auto t1 = std::chrono::steady_clock::now();
  std::cout << std::format(
      "{} milliseconds passed\n",
      std::chrono::duration_cast<std::chrono::milliseconds>(t1 - t0).count());
}

auto main() -> int {
  simple_timer(100);
}