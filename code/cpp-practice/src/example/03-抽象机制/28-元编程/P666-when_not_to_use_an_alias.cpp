#include <type_traits>

template <typename T>
class Error {};

// STAR: 仅有一种候选可能是合法类型时，不应使用别名
template <typename T>
class Intergral {
 public:
  using type = typename std::
      conditional_t<std::is_integral_v<T>, std::make_unsigned_t<T>, Error<T>>;
};

// star: 可以回到显式的、面向实现的 ::type 风格
// star: 也可以引入一个类型函数 Delay，将类型函数的求值延迟到使用时
template <template <typename...> class F, typename... Args>
using Delay = F<Args...>;

template <typename T>
class IntergralDelayed {
 public:
  using type = typename std::conditional_t<std::is_integral_v<T>,
                                           Delay<std::make_unsigned_t, T>,
                                           Error<T>>;
};