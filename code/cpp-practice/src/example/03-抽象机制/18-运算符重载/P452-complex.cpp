class Complex {
 public:
  constexpr Complex(double re = 0.0, double im = 0.0) : re_{re}, im_{im} {}

  [[nodiscard]] constexpr auto real() const -> double { return re_; }
  [[nodiscard]] constexpr auto imag() const -> double { return im_; }

  void real(double re) { re_ = re; }
  void imag(double im) { im_ = im; }

  auto operator+=(Complex a) -> Complex&;  // 需要访问类的数据成员
  auto operator+=(double a) -> Complex&;

 private:
  double re_{};
  double im_{};
};

inline auto Complex::operator+=(Complex a) -> Complex& {
  re_ += a.re_;
  im_ += a.im_;
  return *this;
}

inline auto Complex::operator+=(double a) -> Complex& {
  re_ += a;
  return *this;
}

auto operator==(Complex a, Complex b) {
  return a.real() == b.real() && a.imag() == b.imag();
}

auto operator+(Complex a, Complex b) -> Complex {
  return a += b;  // 通过+= 访问类的数据成员
}

constexpr auto operator""i(long double d) -> Complex {  // 虚部字面值常量
  return {0, static_cast<double>(d)};
}