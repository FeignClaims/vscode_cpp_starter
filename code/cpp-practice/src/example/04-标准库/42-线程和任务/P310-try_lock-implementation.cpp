#include <mutex>

// TODO: better Mutex concept
template <typename M>
concept Mutex = requires(M m) {
  m.try_lock();
  m.unlock();
};

auto my_try_lock(Mutex auto& mtx, Mutex auto&... tail) -> int {
  if (mtx.try_lock()) {
    int n{try_lock(tail...)};
    if (n == -1) return -1;  // 获取了所有锁
    mtx.unlock();            // 回退
    return n + 1;
  }
  return 1;  // 不能获取 mtx
}

auto my_try_lock(Mutex auto& mtx) -> int {
  return (mtx.try_lock()) ? -1 : 0;
}