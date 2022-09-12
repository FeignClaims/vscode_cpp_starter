#include <type_traits>
class substitution_failue {};  // 表示声明失败

template <typename T>
class substitution_succeeded : public std::true_type {};

template <>
class substitution_succeeded<substitution_failue> : public std::false_type {};

template <typename T>
class get_f_result {
 public:
  using type = decltype(check(std::declval<T>()));

 private:
  template <typename X>
  static auto check(X const& x) -> decltype(f(x));  // 可以调用 f(x)

  static auto check(...) -> substitution_failue;  // 不能调用 f(x)
};

// STAR: 对于类型为 X的 x，判断能否调用 f(x)
template <typename T>
class has_f : substitution_succeeded<typename get_f_result<T>::type> {};

template <typename T>
constexpr auto HasF() -> bool {
  return has_f<T>::value;
}