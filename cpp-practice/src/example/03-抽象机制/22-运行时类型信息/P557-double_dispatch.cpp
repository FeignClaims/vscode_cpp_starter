#include <iostream>
#include <utility>
#include <vector>

// STAR: 依赖于多个参数类型的操作：双重分发
class Circle;
class Triangle;

class Shape {
 public:
  [[nodiscard]] virtual auto intersect(const Shape&) const -> bool = 0;
  [[nodiscard]] virtual auto intersect(const Circle&) const -> bool = 0;
  [[nodiscard]] virtual auto intersect(const Triangle&) const -> bool = 0;
};

class Circle : public Shape {
 public:
  [[nodiscard]] auto intersect(const Shape& /*s*/) const -> bool override;
  [[nodiscard]] auto intersect(const Circle& /*unused*/) const -> bool override;
  [[nodiscard]] auto intersect(const Triangle& /*unused*/) const
      -> bool override;
};

class Triangle : public Shape {
 public:
  [[nodiscard]] auto intersect(const Shape& /*s*/) const -> bool override;
  [[nodiscard]] auto intersect(const Circle& /*unused*/) const -> bool override;
  [[nodiscard]] auto intersect(const Triangle& /*unused*/) const
      -> bool override;
};

auto Circle::intersect(const Shape& s) const -> bool {
  return s.intersect(*this);
}
auto Circle::intersect(const Circle& /*unused*/) const -> bool {
  std::cout << "intersect(circle, circle)\n";
  return true;
}
auto Circle::intersect(const Triangle& /*unused*/) const -> bool {
  std::cout << "intersect(circle, triangle)\n";
  return true;
}

auto Triangle::intersect(const Shape& s) const -> bool {
  return s.intersect(*this);
}
auto Triangle::intersect(const Circle& /*unused*/) const -> bool {
  std::cout << "intersect(triangle, circle)\n";
  return true;
}
auto Triangle::intersect(const Triangle& /*unused*/) const -> bool {
  std::cout << "intersect(triangle, triangle)\n";
  return true;
}

void test(Triangle& t, Circle& c) {
  std::vector<std::pair<Shape*, Shape*>> vs{
      {&t, &t}, {&t, &c}, {&c, &t}, {&c, &c}};
  for (auto p : vs) {
    p.first->intersect(*p.second);
  }
}