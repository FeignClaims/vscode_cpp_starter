#include <atomic>
class SpinMutex {
 public:
  void lock() {
    while (flag.test_and_set()) continue;
  }
  void unlock() { flag.clear(); }

 private:
  std::atomic_flag flag{
      ATOMIC_FLAG_INIT};  //\* 无法保证 0 表示清除，因为用此初始化
};