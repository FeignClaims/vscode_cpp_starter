#include <sstream>
#include <stdexcept>
#include <string>
#include <string_view>

// CURRENT_MODE 和 CURRENT_LEVEL 是在程序的编译环境中设置的编译选项
// 这里用下面的 #define 代替
#define CURRENT_MODE Assert::Mode::kIgnore
#define CURRENT_LEVEL 1

namespace Assert {
enum class Mode { kThrow, kTerminate, kIgnore };
constexpr Mode kCurrentMode{CURRENT_MODE};
constexpr int kCurrentLevel{CURRENT_LEVEL};
constexpr int kDefaultLevel{1};

constexpr auto level(int n) -> bool {
  return n <= kCurrentLevel;
}

struct Error : std::runtime_error {
  explicit Error(const std::string& p) : runtime_error(p) {}
};

// 混合生成包含文件名和行号的消息
auto compose(const char* file, int line, std::string_view message)
    -> std::string {
  std::ostringstream os{"("};
  os << file << ", " << line << "):" << message;
  return os.str();
}

template <bool condition = level(kDefaultLevel), typename Except = Error>
void dynamic(bool assertion,
             const std::string& message = "Assert::dynamic failed") {
  if (assertion) {
    return;
  }
  if (kCurrentMode == Assert::Mode::kThrow) {
    throw Except{message};
  }
  if (kCurrentMode == Assert::Mode::kTerminate) {
    std::terminate();
  }
}

// 什么也不做
template <>
void dynamic<false, Error>(bool, const std::string&) {
}

// 默认操作
void dynamic(bool b, const std::string& s) {
  dynamic<true, Error>(b, s);
}

// 默认消息
void dynamic(bool b) {
  dynamic<true, Error>(b);
}
}  // namespace Assert