#include <cstddef>

void myrev(char* str) {
  std::size_t length = [&]() {
    std::size_t i{};
    while (str[i] != '\0') {
      ++i;
    }
    return i;
  }();
  auto swap = [](char& a, char& b) {
    char temp;
    temp = a;
    a = b;
    b = temp;
  };
  for (std::size_t i{}; i < length / 2; ++i) {
    swap(str[i], str[length - 1 - i]);
  }
}