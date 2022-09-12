#include <array>

void f() {
  std::array<int, 8> aa = [] {
    std::array<int, 8> aa{};
    aa.fill(99);
    return aa;
  }();
}