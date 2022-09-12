#include <cctype>
#include <iostream>

auto atoi(const char* str) -> int {
  enum class Type { kOct, kDec, kChar };
  Type type{Type::kOct};
  for (int i{}; str[i] != '\0'; ++i) {
    if (!('0' <= str[i] && str[i] <= '9')) {
      type = Type::kChar;
      break;
    } else if (str[0] == '0' && str[i] != '8' && str[i] != '9') {
      type = Type::kDec;
    } else {
      type = Type::kOct;
    }
  }

  int res{};
  switch (type) {
    case Type::kChar:
      for (int i{}; str[i] != '\0'; ++i) {
        res += static_cast<int>(str[i]);
      }
      break;
    case Type::kOct:
      for (int i{}; str[i] != '\0'; ++i) {
        res = res * 10 + str[i] - '0';
      }
      break;
    case Type::kDec:
      for (int i{}; str[i] != '\0'; ++i) {
        res = res * 8 + str[i] - '0';
      }
  }
  return res;
}

auto main() -> int {
  int i{atoi("0123")};
  std::cout << i;
}