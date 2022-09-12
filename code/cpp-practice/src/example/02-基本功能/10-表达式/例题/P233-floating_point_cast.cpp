#include <cfloat>
#include <limits>

auto main() -> int {
  float f = FLT_MAX;  // 最大的单精度浮点值
  double d = f;       // note: d == f

  double d2 = DBL_MAX;  // 最大的双精度浮点值
  float f2 = d2;        // 如果 FLT_MAX<DBL_MAX，则结果是未定义的

  long double ld = d2;  // note: ld == d2
  long double ld2 = std::numeric_limits<long double>::max();
  double d3 = ld2;  // 如果 sizeof(long double)>sizeof(double)，则结果是未定义的
}