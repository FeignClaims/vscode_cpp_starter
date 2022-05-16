class Window {
 public:
  virtual void draw();  // 显示图像
  // ...
};

class Cowboy {
 public:
  virtual void draw();  // 从枪套中拔枪
  // ...
};

struct WWindow : Window {
  using Window::Window;              // 继承构造函数
  virtual void win_draw() = 0;       // 强制要求派生类必须覆盖
  void draw() final { win_draw(); }  // 显示图像
};

struct CCowboy : Cowboy {
  using Cowboy::Cowboy;              // 继承构造函数
  virtual void cow_draw() = 0;       // 强制要求派生类必须覆盖
  void draw() final { cow_draw(); }  // 从枪套中拔枪
};

class CowboyWindow : public CCowboy, public WWindow {
 public:
  void cow_draw() override;
  void win_draw() override;
};