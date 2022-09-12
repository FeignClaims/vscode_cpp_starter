class Date {};

class IoObj {  // 对象 I/O 系统的基类
  virtual auto clone() -> IoObj* = 0;
};

class IoDate : public Date, public IoObj {};

void f(IoObj* pio) {
  Date* pd{dynamic_cast<Date*>(pio)};
  // ...
}