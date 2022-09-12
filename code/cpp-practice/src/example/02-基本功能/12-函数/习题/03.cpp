#include <iostream>
#include <string>
#include <vector>

auto arguments(int argc, char* argv[]) -> std::vector<std::string>;
void hello(std::vector<std::string> v);

auto main(int argc, char* argv[]) -> int {
  auto args = arguments(argc, argv);
  hello(args);
  return 0;
}

auto arguments(int argc, char* argv[]) -> std::vector<std::string> {
  std::vector<std::string> res;
  for (int i{}; i != argc; ++i) {
    res.emplace_back(argv[i]);
  }
  return res;
}

void hello(std::vector<std::string> v) {
  size_t length{v.size()};
  if (length == 1) {
    std::cout << "Hello, world!\n";
  } else {
    for (size_t i{1}; i < length; ++i) {
      std::cout << "Hello, " << v[i] << "!\n";
    }
  }
}