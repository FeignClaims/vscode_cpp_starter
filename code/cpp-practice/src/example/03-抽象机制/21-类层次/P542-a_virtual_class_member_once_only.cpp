class Window {
 public:
  // 基本要素
  virtual void draw();
};

class WindowWithBorder : public virtual Window {
  // 边界元素
 public:
  void draw() override;

 protected:
  void own_draw();  // 显示边界
};

class WindowWithMenu : public virtual Window {
  // 菜单元素
 public:
  void draw() override;

 protected:
  void own_draw();  // 显示菜单
};

class Clock : public WindowWithBorder, public WindowWithMenu {
  // 时钟元素
 public:
  void draw() override;

 protected:
  void own_draw();  // 显示表盘和指针
};

void WindowWithBorder::draw() {
  Window::draw();
  own_draw();  // 显示边界
}

void WindowWithMenu::draw() {
  Window::draw();
  own_draw();  // 显示菜单
}

void Clock::draw() {
  Window::draw();
  WindowWithBorder::own_draw();
  WindowWithMenu::own_draw();
  own_draw();  // 显示表盘和指针
}