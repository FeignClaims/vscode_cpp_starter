#include <type_traits>

template <typename T>
void my_fct(T& x) noexcept(std::is_pod_v<T>());