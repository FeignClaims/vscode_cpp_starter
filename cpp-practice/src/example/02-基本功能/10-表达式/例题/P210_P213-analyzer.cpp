#include "P210_P213-analyzer.hpp"

#include "P210-token.hpp"
#include "P213-token_stream.hpp"

#include <map>
#include <stdexcept>
#include <string>

auto prim(bool get,
          std::map<std::string, double>& table,
          TokenStream& ts) -> double {  // 处理初等项
  if (get) ts.get();                    // 读取下一个单词
  switch (ts.current().kind) {
    case Kind::kNumber: {  // 浮点数常量
      // STAR: 条件分支里通过块声明并初始化变量
      double v{ts.current().number_value};
      ts.get();
      return v;
    }
    case Kind::kName: {
      double& v{table[ts.current().string_value]};  // 找到对应的项
      if (ts.get().kind == Kind::kAssign) {  // 看到了 '='：赋值运算符
        v = expr(true, table, ts);
        return v;
      }
    }
    case Kind::kMinus:  // 一元减法
      return -prim(true, table, ts);
    case Kind::kLp: {
      auto e = expr(true, table, ts);
      if (ts.current().kind != Kind::kRp) {
        throw std::runtime_error{"')' expected"};
      }
      ts.get();  // 吃掉了 ')'
      return e;
    }
    default:
      throw std::runtime_error{"primary expected"};
  }
}

auto term(bool get,
          std::map<std::string, double>& table,
          TokenStream& ts) -> double {  // 乘法和除法
  double left{prim(get, table, ts)};

  while (true) {
    switch (ts.current().kind) {
      case Kind::kMul:
        left *= prim(true, table, ts);
        break;
      case Kind::kDiv: {
        auto d = prim(true, table, ts);
        if (d != 0.0) {
          left /= d;
          break;
        }
        throw std::runtime_error{"divide by 0"};
      }
      default:
        return left;
    }
  }
}

auto expr(bool get, std::map<std::string, double>& table, TokenStream& ts)
    -> double {
  double left{term(get, table, ts)};

  while (true) {
    switch (ts.current().kind) {
      case Kind::kPlus:
        left += term(true, table, ts);
        break;
      case Kind::kMinus:
        left -= term(true, table, ts);
        break;
      default:
        return left;
    }
  }
}