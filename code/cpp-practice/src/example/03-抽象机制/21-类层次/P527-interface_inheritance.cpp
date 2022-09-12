class LvalBox {
 public:
  virtual ~LvalBox() = default;

  virtual auto get_value() -> int = 0;
  virtual void set_value(int value) = 0;
  virtual void reest_value(int value) = 0;
  virtual void prompt() = 0;
  [[nodiscard]] virtual auto was_changed() const -> bool = 0;
};