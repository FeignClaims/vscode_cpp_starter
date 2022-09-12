template <bool C, typename T, typename F>  // 通用模板
class conditional {
 public:
  using type = T;
};

template <typename T, typename F>  // false 的特例化版本
class conditional<false, T, F> {
 public:
  using type = F;
};

template <bool B, typename T, typename F>
using Conditional = typename conditional<B, T, F>::type;