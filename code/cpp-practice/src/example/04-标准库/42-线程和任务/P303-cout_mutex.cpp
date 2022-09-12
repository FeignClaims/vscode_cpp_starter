#include <iostream>
#include <mutex>
#include <thread>

std::mutex cout_mutex;  // 表示使用 cout 的权限

template <typename Arg1, typename Arg2, typename Arg3>
void write(Arg1 a1, Arg2 a2 = {}, Arg3 a3 = {}) {
  auto name = std::this_thread::get_id();
  cout_mutex.lock();
  std::cout << "From thread " << name << " : " << a1 << a2 << a3;
  cout_mutex.unlock();
}
