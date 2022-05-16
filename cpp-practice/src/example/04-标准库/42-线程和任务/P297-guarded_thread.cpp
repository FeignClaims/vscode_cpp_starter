#include <thread>

// star: RAII，隐式调用 join() 的析构函数
//\* 保证 thread（句柄）销毁之前，系统线程执行完毕
class GuardedThread : std::thread {
 public:
  using thread::thread;
  ~GuardedThread() {
    if (joinable()) join();
  }
};