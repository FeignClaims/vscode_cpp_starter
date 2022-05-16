// star: constexpr 版本，既可用于编译时，也可用于运行时
constexpr auto fac1(int i) -> int {
  return (i < 2) ? 1 : fac1(i - 1);
}

// star: 模板（元编程）版本，只能用于编译时
// 递归调用
template <int N>
constexpr auto fac2() -> int {
  return N * fac2<N - 1>();
}
// 一个特例化版本作为递归的终止条件
template <>
constexpr auto fac2<1>() -> int {
  return 1;
}

// STAR: 元编程迭代过程中使用类，以处理更复杂的状态或更精细的参数化
template <int N>
class Fac {
 public:
  static const int value{N * Fac<N - 1>::value};
};

template <>
class Fac<1> {
  static const int value{1};
};