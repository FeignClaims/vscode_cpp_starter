#include <atomic>

template <typename T>
class SharedPtr {
 private:
  T* p;                   // 指向共享对象的指针
  std::atomic<int>* puc;  // 指向使用计数的指针
 public:
  // ...
  ~SharedPtr() {
    if (--*puc) delete p;
  }
};