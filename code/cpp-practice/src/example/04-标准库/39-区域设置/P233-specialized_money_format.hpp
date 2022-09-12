#include <cstddef>
#include <locale>
#include <string>
class MyMoneyIo : public std::moneypunct<char, true> {
 private:
  static const pattern pat;

 public:
  explicit MyMoneyIo(std::size_t r = {}) : std::moneypunct<char, true>(r) {}

  [[nodiscard]] auto do_decimal_point() const -> char_type override {
    return '.';
  }
  [[nodiscard]] auto do_thousands_sep() const -> char_type override {
    return ',';
  }
  [[nodiscard]] auto do_grouping() const -> std::string override {
    return "\003\003\003";
  }

  [[nodiscard]] auto do_curr_symbol() const -> string_type override {
    return "USD ";
  }
  [[nodiscard]] auto do_positive_sign() const -> string_type override {
    return "";
  }
  [[nodiscard]] auto do_negative_sign() const -> string_type override {
    return "()";
  }

  [[nodiscard]] auto do_frac_digits() const -> int override {
    return 2;
  }  // 小数点后两位数字

  [[nodiscard]] auto do_pos_format() const -> pattern override { return pat; }
  [[nodiscard]] auto do_neg_format() const -> pattern override { return pat; }
};

const MyMoneyIo::pattern MyMoneyIo::pat{sign, symbol, value, none};