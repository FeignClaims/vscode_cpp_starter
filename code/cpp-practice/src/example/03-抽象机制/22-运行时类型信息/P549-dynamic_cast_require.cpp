class IvalBox {
 public:
  virtual ~IvalBox() = default;
  virtual void ival_test();
};

class IvalSlider : public IvalBox {};

struct Date {
  int x;
};

class MySlider : public IvalSlider {  // 多态基类（IvalSlider 有虚函数）
};

class MyDate : public Date {  // 基态非多态（Date 没有虚函数）
  // ...
};

void g(IvalBox* pb, Date* pd) {
  MySlider* pd1{
      dynamic_cast<MySlider*>(pb)};  //\; 一个 IvalSlider 是一个 IvalBox
  MyDate* pd2{dynamic_cast<MyDate*>(pd)};  //\! Date 非多态
}