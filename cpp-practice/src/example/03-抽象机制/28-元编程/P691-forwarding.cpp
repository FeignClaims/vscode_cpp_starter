#include <utility>
template <typename F, typename... T>
void call(F&& f, T&&... t) {
  f(std::forward<T>(t)...);
}