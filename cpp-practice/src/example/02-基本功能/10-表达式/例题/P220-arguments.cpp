#include <string>
#include <vector>

auto arguments(int argc, char* argv[]) -> std::vector<std::string> {
  std::vector<std::string> res;
  for (int i = 0; i != argc; ++i) {
    res.emplace_back(argv[i]);
  }
  return res;
}

auto main(int argc, char* argv[]) -> int {
  std::vector<std::string> v{arguments(argc, argv)};
}