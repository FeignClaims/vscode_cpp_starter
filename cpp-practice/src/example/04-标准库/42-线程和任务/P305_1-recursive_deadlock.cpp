#include <iostream>
#include <mutex>
#include <thread>

std::mutex cout_mutex;

void write(auto a, auto... tail) {
  cout_mutex.lock();
  std::cout << a;
  write(tail...);
  cout_mutex.unlock();
}