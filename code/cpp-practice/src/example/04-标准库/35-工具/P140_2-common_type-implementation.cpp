#include <utility>

template <typename... T>
struct common_type;

template <typename T>
struct common_type<T> {
  using type = T;
};

template <typename T, typename U>
struct common_type<T, U> {
  using type = decltype(true ? std::declval<T>() : std::declval<U>());
};

template <typename T, typename U, typename... V>
struct common_type<T, U, V...> {
  using type =
      typename common_type<typename common_type<T, U>::type, V...>::type;
};