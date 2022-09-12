#include <cstdlib>
#include <exception>
#include <iostream>
auto main() -> int try {
  // ...
} catch (std::exception& e) {
  std::cout << e.what() << '\n';
  std::abort();
} catch (...) {
  std::cout << "Unkown Error(s)!\n";
  std::abort();
}