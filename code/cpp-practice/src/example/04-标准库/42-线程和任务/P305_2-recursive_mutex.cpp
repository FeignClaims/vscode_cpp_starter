#include <iostream>
#include <mutex>
#include <thread>

std::recursive_mutex
    cout_mutex;  // 改为 recursive_mutex 以允许单一 thread 反复获取

void write(auto a, auto... tail) {
  cout_mutex.lock();
  std::cout << a;
  write(tail...);
  cout_mutex.unlock();
}