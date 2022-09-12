#include <iostream>
#include <limits>

auto main() -> int {
  if (std::numeric_limits<char>::is_signed) {
    std::cout << "signed\n";
  } else {
    std::cout << "unsigned\n";
  }

  return 0;
}