#include <string>
class Entry2 {  // 用 union 规定了两种不同的表示形式
 public:
  struct BadEntry {};  // 用于处理异常

  Entry2(const Entry2&);

  auto operator=(const Entry2&)
      -> Entry2&;  // 因为存在 string 变量，所以是必需的

  ~Entry2();

  [[nodiscard]] auto name() -> std::string { return name_; }
  [[nodiscard]] auto name() const -> const std::string { return name_; }
  [[nodiscard]] auto number() const -> int;
  [[nodiscard]] auto text() const -> std::string;

  void set_number(int n);
  void set_text(const std::string&);

 private:
  std::string name_;
  enum class Tag { number, text };
  Tag type_;  // 判别式

  union {  // 表示形式
    int i_;
    std::string str_;  // string 有默认构造函数、拷贝操作及析构函数
  };
};

auto Entry2::operator=(const Entry2& e) -> Entry2& {
  if (type_ == Tag::text && e.type_ == Tag::text) {
    str_ = e.str_;  // 常规的 string 赋值
    return *this;
  }

  if (type_ == Tag::text) str_.~basic_string();  // 显式地销毁
  switch (e.type_) {
    case Tag::number:
      i_ = e.i_;
      break;
    case Tag::text:
      new (&str_) std::string{e.str_};  // new 的作用是显式地构造 string
      type_ = e.type_;
  }

  return *this;
}

Entry2::~Entry2() {
  if (type_ == Tag::text) str_.~basic_string();
}

void Entry2::set_number(int n) {
  if (type_ == Tag::text) {
    str_.~basic_string();  // 显式地销毁 string
    type_ = Tag::number;
  }
  i_ = n;
}

void Entry2::set_text(const std::string& ss) {
  if (type_ == Tag::text) {
    str_ = ss;
  } else {
    new (&str_) std::string{ss};  // new 的作用是显式地构造 string
    type_ = Tag::text;
  }
}

auto Entry2::number() const -> int {
  if (type_ != Tag::number) throw BadEntry{};
  return i_;
}

auto Entry2::text() const -> std::string {
  if (type_ != Tag::text) throw BadEntry{};
  return str_;
}