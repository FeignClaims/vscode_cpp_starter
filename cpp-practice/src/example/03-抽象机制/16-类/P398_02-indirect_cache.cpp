#include <string>

// STAR: 将要在 const 函数中改变的数据放在独立对象中
struct cache {
  bool valid;
  std::string rep;
};

class Date {
 public:
  [[nodiscard]] auto string_rep() const -> std::string;  // 字符串表示
 private:
  void compute_cache_value() const;  // 填入 cache 指向的内存

  // STAR: const 不能（传递地）应用到通过指针或引用访问的对象
  cache* c;  // 在构造函数中初始化
};

auto Date::string_rep() const -> std::string {
  if (!c->valid) {
    compute_cache_value();
    c->valid = true;
  }
  return c->rep;
}