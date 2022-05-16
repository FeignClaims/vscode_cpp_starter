#include <cmath>
#include <iostream>
void myitoa(int num, char b[], int size) {
  int figure{static_cast<int>(std::log10(num))};
  for (int i{}, theten{}; i < size && num != 0; ++i) {
    theten = static_cast<int>(std::pow(10, figure));
    b[i] = static_cast<char>(num / theten + '0');
    num %= theten;
    --figure;
  }
}

auto main() -> int {
  char b[100]{};
  myitoa(123, b, 100);
  std::cout << b;
}