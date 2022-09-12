#include <memory>
#include <utility>

auto f(std::unique_ptr<int> p) -> std::unique_ptr<int> {
  ++*p;
  return p;
}

void f2(const std::unique_ptr<int>& p) {
  ++*p;
}

void use() {
  auto p = std::make_unique<int>(7);
  p = f(p);             //\! 无拷贝构造函数
  p = f(std::move(p));  // 转移所有权，又转移回来
  f2(p);                // 传递引用
}