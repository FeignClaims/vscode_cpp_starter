#include "P704-matrix.hpp"

/**
 * 简化 U = M * V + W;
 */

using Mat2d = Matrix<double, 2>;
using Vec = Matrix<double, 1>;

template <typename U, typename M, typename V, typename W>
void mul_add_and_assign(U*, M*, V*, W*);

// STAR: 合成闭包对象（composition closure object）：用于推迟求值的对象
//\* 简称合成器（compositor）
// STAR: 表达式模板（expression template）：推迟所有运算的执行
//\* 系统地使用函数对象来将表达式描述为抽象语法树（Abstract Syntax
// Tree，AST）
class MVmul {
 public:
  MVmul(const Mat2d& mm, const Vec& vv) : m{mm}, v{vv} {}

  explicit operator Vec();  // 求值并返回结果

  const Mat2d& m;
  const Vec& v;
};

class MVmulVadd {
 public:
  MVmulVadd(const MVmul& mv, const Vec& vv) : m{mv.m}, v{mv.v}, v2{vv} {}

  explicit operator Vec();  // 求值并返回结果

  const Mat2d& m;
  const Vec& v;
  const Vec& v2;
};

inline auto operator+(const MVmul& mv, const Vec& vv) -> MVmulVadd {
  return {mv, vv};
}

// 除了保存运算对象的引用外什么都不做——M * V 的求值被推迟了
inline auto operator*(const Mat2d& mm, const Vec& vv) {
  return MVmul(mm, vv);
}

template <>
class Matrix<double, 1> {  // 特例化（只用于本例）
                           // ...
 public:
  explicit Matrix(const MVmulVadd m) {  // 用 m 的结果进行初始化
    // 为元素分配空间等工作
    mul_add_and_assign(this, &m.m, &m.v, &m.v2);
  }

  auto operator=(const MVmulVadd& m) -> Matrix& {  // 将 m 的结果赋予 *this
    mul_add_and_assign(this, &m.m, &m.v, &m.v2);
    return *this;
  }
  // ...
};