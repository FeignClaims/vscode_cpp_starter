#ifndef THECPPPROGRAMMINGLANGUAGE_TOKENSTREAM_HPP
#define THECPPPROGRAMMINGLANGUAGE_TOKENSTREAM_HPP

#include "P210-token.hpp"

#include <cctype>
#include <iostream>

class TokenStream {
 public:
  explicit TokenStream(std::istream& s) : ip_{&s}, owns_{false} {}
  explicit TokenStream(std::istream* p) : ip_{p}, owns_{true} {}

  ~TokenStream() { close(); }

  inline auto get() -> Token;  // 读取并返回下一个单词
  auto current() -> Token& {   // 刚刚读入的单词
    return ct_;
  }

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

  std::istream* ip_;      // 指向输入流的指针
  bool owns_;             // TokenStream 有流吗？
  Token ct_{Kind::kEnd};  // 当前单词
};

// P215
auto TokenStream::get() -> Token {
  char ch{};

  do {  // 跳过除 '\n' 之外的其他空白符
    if (!ip_->get(ch)) return ct_ = {Kind::kEnd};
  } while (ch != '\n' && (std::isspace(ch) != 0));

  switch (ch) {
    case 0:
      // STAR: 赋值并返回
      return ct_ = {Kind::kEnd};
    case ';':  // 表达式终结符，输出
    case '*':
    case '/':
    case '+':
    case '-':
    case '(':
    case ')':
    case '=':
      return ct_ = {static_cast<Kind>(ch)};
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
    case '.':
      ip_->putback(ch);  // 把第一个数字（或者 .）放回输入流中
      *ip_ >> ct_.number_value;  // 把数字读入 ct_
      ct_.kind = Kind::kNumber;
      return ct_;
    default:  // 名字，名字 =，或者错误
      if (std::isalpha(ch) != 0) {
        ct_.string_value = ch;
        while (ip_->get(ch) && (std::isalnum(ch) != 0)) {
          ct_.string_value += ch;  // 把 ch 加到 ct_.string_value 的末尾
        }
        ip_->putback(ch);
        return ct_ = {Kind::kName};
      }
      /* error("bad token"); */
      return ct_ = {Kind::kPrint};
  }
}

#endif