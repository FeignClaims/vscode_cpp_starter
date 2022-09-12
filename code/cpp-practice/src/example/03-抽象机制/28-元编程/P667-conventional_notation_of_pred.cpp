#include <type_traits>

// STAR: 用 is_* constexpr 函数 为 is_* 函数提供常用的 () 调用语法支持
template <typename T>
constexpr auto IsPod() -> bool {
  return std::is_pod_v<T>;
}