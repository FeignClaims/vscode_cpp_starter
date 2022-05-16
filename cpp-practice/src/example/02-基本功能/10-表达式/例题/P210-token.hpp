#ifndef THECPPPROGRAMMINGLANGUAGE_TOKEN_HPP
#define THECPPPROGRAMMINGLANGUAGE_TOKEN_HPP

#include <string>

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

#endif