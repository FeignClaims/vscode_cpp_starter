#include <iostream>

class MyBase {
 public:
  // ...
  virtual auto put(std::ostream& s) const
      -> std::ostream& = 0;  // 将 *this 写到 s
};

// STAR: 双重分发实现 virtual 输出
auto operator<<(std::ostream& s, const MyBase& r) -> std::ostream& {
  return r.put(s);  // 使用正确的 put()
}

class Sometype : public MyBase {
 public:
  // ...
  auto put(std::ostream& s) const -> std::ostream& override;  // 实际输出函数
};

void f(const MyBase& r, Sometype& s) {  // 使用 << 调用正确的 put()
  std::cout << r << s;
}