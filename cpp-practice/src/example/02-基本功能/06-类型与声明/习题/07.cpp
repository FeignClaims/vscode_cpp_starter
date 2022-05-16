#include <iomanip>
#include <iostream>

void char2int(char ch);

auto main() -> int {
  for (char ch{'0'}; ch <= 'z'; ++ch) {
    char2int(ch);
  }
}

void char2int(char ch) {
  std::cout << ch << ' ' << std::setw(3) << static_cast<int>(ch) << '\n';
}