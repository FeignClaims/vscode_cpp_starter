class IvalSlider {
 public:
  virtual ~IvalSlider() = default;

  virtual void ival_test();
};

class BBSlider {
 public:
  virtual ~BBSlider() = default;

  virtual void bb_test();
};

class BBIvalSlider : public IvalSlider, protected BBSlider {};

void f(BBIvalSlider* p) {
  IvalSlider* pi1{p};
  IvalSlider* pi2{dynamic_cast<IvalSlider*>(p)};

  BBSlider* pbb1{p};  //\! BBSlider 是一个保护基类
  BBSlider* pbb2{dynamic_cast<BBSlider*>(p)};
}