#include <chrono>
#include <ratio>
#include <type_traits>

template <typename Rep1, typename P1, typename Rep2, typename P2>
struct std::common_type<std::chrono::duration<Rep1, P1>,
                        std::chrono::duration<Rep2, P2>> {
  using type = std::chrono::duration < std::common_type_t<Rep1, Rep2>,
        std::__ratio_gcd<P1, P2>;
};

template <typename Clock, typename Duration1, typename Duration2>
struct std::common_type<std::chrono::time_point<Clock, Duration1>,
                        std::chrono::time_point<Clock, Duration2>> {
  using type = std::chrono::time_point < Clock,
        std::common_type_t<Duration1, Duration2>;
};