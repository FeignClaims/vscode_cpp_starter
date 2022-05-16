#include <vector>

// STAR: 依靠模板实参来显式化依赖关系，简化思考、访问局部信息。
void fff() {
  struct S {
    int a, b;
  };

  std::vector<S> vs;
}