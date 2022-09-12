#include <iostream>
#include <string>

namespace lexer {
enum class Kind : char {
  kName,
  kNumber,
  kEnd,
  kPlus = '+',
  kMinus = '-',
  kMul = '*',
  kDiv = '/',
  kPrint = ';',
  kAssign = '=',
  kLp = '(',
  kRp = ')'
};

struct Token {
  Kind kind;
  std::string string_value{};
  double number_value{};
};

class TokenStream {
 public:
  TokenStream() = default;
  explicit TokenStream(std::istream& s)
      : ip_{&s}, owns_{false}, ct_{Kind::kEnd} {}
  explicit TokenStream(std::istream* p)
      : ip_{p}, owns_{true}, ct_{Kind::kEnd} {}

  ~TokenStream() { close(); }

  auto get() -> Token;       // 读取并返回下一个单词
  auto current() -> Token&;  // 最近读取的单词

  void set_input(std::istream& s) {
    close();
    ip_ = &s;
    owns_ = false;
  }
  void set_input(std::istream* p) {
    close();
    ip_ = p;
    owns_ = true;
  }

 private:
  void close() {
    if (owns_) delete ip_;
  }

  std::istream* ip_{};    // 指向输入流的指针
  bool owns_{};           // TokenStream 拥有这个流吗？
  Token ct_{Kind::kEnd};  // 当前的单词
};

extern TokenStream ts;
}  // namespace lexer