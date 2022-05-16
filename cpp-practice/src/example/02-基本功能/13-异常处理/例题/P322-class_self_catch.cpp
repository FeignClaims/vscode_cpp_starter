#include <exception>
#include <string>
#include <vector>
class X {
 public:
  X(int, int);

 private:
  std::vector<int> vi_;
  std::vector<std::string> vs_;
};

X::X(int sz1, int sz2) try : vi_(sz1), vs_(sz2) {
  // ...
} catch (std::exception& err) {  // 捕获 vi 和 vs 抛出的异常
  // ...
}