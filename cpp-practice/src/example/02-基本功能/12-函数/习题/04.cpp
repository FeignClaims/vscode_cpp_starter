#include <fstream>
#include <iostream>
#include <string>
#include <vector>

auto arguments(int argc, char* argv[]) -> std::vector<std::string>;

auto main(int argc, char* argv[]) -> int {
  auto args = arguments(argc, argv);
  std::string temp{};
  for (size_t i{1}; i < args.size(); ++i) {
    std::ifstream infile{args[i]};
    while (infile.good()) {
      getline(infile, temp);
      std::cout << temp << '\n';
    }
  }
}

auto arguments(int argc, char* argv[]) -> std::vector<std::string> {
  std::vector<std::string> res;
  for (int i{}; i < argc; ++i) {
    res.emplace_back(argv[i]);
  }
  return res;
}