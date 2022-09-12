#include <cstddef>

class NotOnStack {
 public:
  ~NotOnStack() = delete;
};

class NotOnFreeStore {
 public:
  auto operator new(size_t) -> void* = delete;
};

void f() {
  NotOnStack v1;      //\! 不能销毁
  NotOnFreeStore v2;  // 正确

  auto* p1 = new NotOnStack;      // 正确
  auto* p2 = new NotOnFreeStore;  // 错误：不能分配
}