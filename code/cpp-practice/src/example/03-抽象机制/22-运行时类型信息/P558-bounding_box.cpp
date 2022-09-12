#include <map>
#include <string>
#include <typeinfo>

// STAR: 依赖于多个参数类型的操作：预计算值
// star: 对于形状，定义一个边框
class Rectangle {};

class Shape {
 public:
  [[nodiscard]] virtual auto box() const -> Rectangle = 0;  // 包围形状的矩形
};

class Circle : public Shape {
 public:
  [[nodiscard]] auto box() const -> Rectangle override;
};

class Triangle : public Shape {
 public:
  [[nodiscard]] auto box() const -> Rectangle override;
};

auto intersect1(const Rectangle&, const Rectangle) -> bool;  // 计算很简单

auto intersect1(const Shape& s1, const Shape& s2) -> bool {
  return intersect1(s1.box(), s2.box());
}

// star: 预先计算一个查询表，保存所有类型组合对应的函数
auto index(const std::type_info& ti1, const std::type_info& ti2) -> std::string;

auto intersect_tbl() -> std::map<std::string, bool>& {
  static std::map<std::string, bool> m;
  return m;
}

auto intersect2(const Shape& s1, const Shape& s2) -> bool {
  auto i = index(typeid(s1), typeid(s2));
  return intersect_tbl()[i];
}