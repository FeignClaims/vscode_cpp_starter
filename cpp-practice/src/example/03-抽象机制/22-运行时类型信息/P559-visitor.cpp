#include <iostream>
#include <utility>
#include <vector>

// STAR: 依赖于多个参数类型的操作：访问者模式
class Expr;
class Stmt;

class Visitor {
 public:
  virtual void accept(Expr&) = 0;
  virtual void accept(Stmt&) = 0;
};

class Node {
 public:
  virtual void accept(Visitor&) = 0;
};

class Expr : public Node {
 public:
  void accept(Visitor& v) override { v.accept(*this); }
};

class Stmt : public Node {
 public:
  void accept(Visitor& v) override { v.accept(*this); }
};

class Do1Visitor : public Visitor {
  void accept(Expr&) override { std::cout << "do1 to Expr\n"; }
  void accept(Stmt&) override { std::cout << "do1 to Stmt\n"; }
};

class Do2Visitor : public Visitor {
  void accept(Expr&) override { std::cout << "do2 to Expr\n"; }
  void accept(Stmt&) override { std::cout << "do2 to Stmt\n"; }
};

void test(Expr& e, Stmt& s) {
  Do1Visitor do1;
  Do2Visitor do2;

  std::vector<std::pair<Node*, Visitor*>> vn{
      {&e, &do1}, {&s, &do1}, {&e, &do2}, {&s, &do2}};
  for (auto p : vn) {
    p.first->accept(*p.second);
  }
}