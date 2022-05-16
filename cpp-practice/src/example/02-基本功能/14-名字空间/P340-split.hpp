#include <sstream>
#include <string>
#include <vector>

auto split(const std::string& s) -> std::vector<std::string> {
  std::vector<std::string> res;
  std::istringstream iss{s};
  for (std::string buf; iss >> buf;) {
    res.emplace_back(buf);
  }
  return res;
}