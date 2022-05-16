#include <ios>
#include <iostream>
#include <sstream>
#include <string>

auto main() -> int {
  std::string input{"0 1 2 3 4"};
  std::istringstream iss{input};
  std::string s;
  for (char ch{}; iss >> ch;) {
    s += ch;
  }
  std::cout << s;  // 打印 "01234"

  s.clear();

  std::istringstream iss2{input};
  iss2 >> std::noskipws;
  for (char ch{}; iss2 >> ch;) {
    s += ch;
  }
  std::cout << s;  // 打印 "0 1 2 3 4"
}