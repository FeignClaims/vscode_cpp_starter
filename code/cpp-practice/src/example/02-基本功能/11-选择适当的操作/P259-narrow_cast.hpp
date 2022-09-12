#include <stdexcept>

// STAR: narrow_cast（详见 gsl）
template <typename Target, typename Source>
auto narrow_cast(Source v) {
  auto r = static_cast<Target>(v);  // 把值转换成目标类型
  if (static_cast<Source>(r) != v) {
    throw std::runtime_error("narrow_cast<>() failed");
  }
  return r;
}