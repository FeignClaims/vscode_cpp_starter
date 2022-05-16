class Nonlocal {
 public:
  void destroy() { this->~Nonlocal(); }  // 显式析构

 private:
  ~Nonlocal() = default;  // 不能隐式析构
};

void user() {
  Nonlocal x;             //\! 不能析构一个 Nonlocal
  auto p = new Nonlocal;  // 正确
  // ...
  delete p;      //\! 不能析构一个 Nonlocal
  p->destroy();  // 正确
}