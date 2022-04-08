#include <format>
#include <iostream>

int x;

int main() {
  int x{};
  std::cout << std::format("{}\n", x);
}