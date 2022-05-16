#include <memory>

template <typename T, typename... Args>
auto make_unique(Args&&... args) -> std::unique_ptr<T> {  // 默认释放器版本
  return std::unique_ptr<T>{new T{args...}};
}