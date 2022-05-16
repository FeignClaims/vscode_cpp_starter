#include <tuple>

template <unsigned N, typename... Cases>  // 一般情况：不会被实例化
class select;

template <unsigned N, typename T, typename... Cases>
class select<N, T, Cases...> : public select<N - 1, Cases...> {};

template <typename T, typename... Cases>  // 最终情况：N == 0
class select<0, T, Cases...> {
  using type = T;
};

template <unsigned N, typename... Cases>
using Select = typename select<N, Cases...>::type;

template <int I, typename T1, typename T2, typename T3, typename T4>
auto get(std::tuple<T1, T2, T3, T4>& t) -> Select<I, T1, T2, T3, T4>;