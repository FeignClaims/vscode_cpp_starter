#include <mutex>
#include <string>
#include <vector>

void use1(std::mutex& mtx, std::vector<std::string>& vs, int i) {
  std::lock_guard<std::mutex> g{mtx};
  if (i < 0) return;
  std::string s = vs[i];
}

void use2(std::mutex& mtx, std::vector<std::string>& vs, int i) {
  if (i < 0) return;
  std::lock_guard<std::mutex> g{mtx};
  std::string s = vs[i];
}

void use3(std::mutex& mtx, std::vector<std::string>& vs, int i) {
  if (i < 0) return;
  std::string s;
  {
    std::lock_guard<std::mutex> g{mtx};
    s = vs[i];
  }
}

void use4(std::mutex& mtx, std::vector<std::string>& vs, int i) {
  if (i < 0) return;
  std::string s = [&] {
    std::string temp;
    std::lock_guard<std::mutex> g{mtx};
    temp = vs[i];
    return temp;
  }();
}