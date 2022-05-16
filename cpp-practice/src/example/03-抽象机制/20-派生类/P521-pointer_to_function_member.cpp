class StdInterface {
 public:
  virtual ~StdInterface() = default;

  virtual void start() = 0;
  virtual void suspend() = 0;
  virtual void resume() = 0;
  virtual void full_size() = 0;
  virtual void small() = 0;
};

using PstdMem = void (StdInterface::*)();  // 成员指针类型

void f(StdInterface* p) {
  PstdMem s{&StdInterface::suspend};  // 指向 suspend() 的指针
  p->suspend();                       // 直接调用
  p->*s();                            // 通过成员指针调用
}