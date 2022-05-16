/**
 * TODO:
 *\>Define a class Int that acts exactly like the built-in type int, except that
 *\>it throws exceptions rather than overflowing or underflowing.
 */

class Int {
 public:
  Int() = default;
  Int(const Int& i) = default;
  Int(Int&& i) = default;

  auto operator=(const Int& i) -> Int& = default;
  auto operator=(Int&& i) -> Int& = default;

  ~Int() = default;

  [[nodiscard]] auto value() const -> int { return value_; }
  explicit operator bool() const {
    if (value_) {
      return true;
    }
    return false;
  }

 private:
  int value_{};
};