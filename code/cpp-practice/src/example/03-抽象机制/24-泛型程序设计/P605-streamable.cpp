#include <concepts>
#include <iostream>

template <typename T>
concept InputStreamable = requires(std::istream& is, T value) {
  { is >> value } -> std::convertible_to<std::istream&>;
};

template <typename T>
concept OutputStreamable = requires(std::ostream& os, T value) {
  { os << value } -> std::convertible_to<std::ostream&>;
};

template <typename T>
concept Streamable = InputStreamable<T> && OutputStreamable<T>;