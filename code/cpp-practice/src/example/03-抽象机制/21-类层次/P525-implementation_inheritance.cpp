class LvalBox {
 public:
  LvalBox(int low, int high) : value_{low}, low_{low}, high_{high} {}

  virtual auto get_value() -> int {  // 供应用程序使用
    changed_ = false;
    return value_;
  }
  virtual void set_value(int value) {  // 供用户使用
    changed_ = true;
    value_ = value;
  }
  virtual void reset_value(int value) {  // 供应用程序使用
    changed_ = false;
    value_ = value;
  }
  virtual void prompt() {}
  [[nodiscard]] virtual auto was_changed() const -> bool { return changed_; }

 protected:
  int value_;
  int low_;
  int high_;
  bool changed_{};  // 用户通过 set_value() 改变
};