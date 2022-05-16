#include <iostream>
#include <string>
#include <vector>

void error(int severity,
           const std::vector<std::string>& err) {  // 与之前几乎一样
  for (const auto& s : err) {
    std::cerr << s << ' ';
  }
  std::cerr << '\n';
  if (severity) exit(severity);
}

auto arguments(int argc, char* argv[])
    -> std::vector<std::string> {  // 把参数打包在一起
  std::vector<std::string> res;
  for (int i{}; i != argc; ++i) {
    res.emplace_back(argv[i]);
  }
  return res;
}

auto main(int argc, char* argv[]) -> int {
  auto args = arguments(argc, argv);
  error((args.size() < 2) ? 0 : 1, args);
  // ...
}