#include <string>

class Date {
 public:
  auto string_rep() const -> std::string;  // 字符串表示
 private:
  void compute_cache__value() const;  // 填入（可变的）缓存

  // STAR: 将要在 const 函数中改变的数据声明为 mutable
  mutable bool cache_valid;
  mutable std::string cache;
};

auto Date::string_rep() const -> std::string {
  if (!cache_valid) {
    compute_cache__value();
    cache_valid = true;
  }
  return cache;
}