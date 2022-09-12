#include <concepts>

template <typename T>
concept Ordered = std::totally_ordered<T> && std::regular<T>;