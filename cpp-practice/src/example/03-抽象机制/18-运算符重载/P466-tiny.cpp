class Tiny {
 public:
  class BadRange {};

  explicit Tiny(int i) { assign(i); }
  auto operator=(int i) -> Tiny& {
    assign(i);
    return *this;
  }

  explicit operator int() const { return v; }  // 转换成 int 的函数
 private:
  void assign(int i) {
    if (i & ~077) throw BadRange{};
    v = static_cast<char>(i);
  }
  char v{};
};