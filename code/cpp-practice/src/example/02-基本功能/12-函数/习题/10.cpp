#include <exception>
#include <iostream>
#include <stdexcept>
#include <string>
#include <string_view>

void convert(std::string_view sv = {});

auto main(int argc, char* argv[]) -> int {
  try {
    if (argc == 1) {
      convert();
    } else if (argc == 2) {
      convert(argv[1]);
    } else {
      throw std::runtime_error("too many arguments!");
    }
  } catch (std::exception e) {
    e.what();
  }
}

void convert(std::string_view sv) {
  char ch{};
  int index{};
  std::string res;
  while (std::cin >> ch && ch != 'q') {
    if (sv == std::string_view{}) {
      res += ch;
    } else {
      res += static_cast<char>(ch * sv[index++]);
    }
  }
  std::cout << res;
}