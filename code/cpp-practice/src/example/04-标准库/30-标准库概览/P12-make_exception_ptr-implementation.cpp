#include <exception>

template <typename E>
auto make_exception_ptr(E e) noexcept -> std::exception_ptr {
  try {
    throw e;
  } catch (...) {
    return std::current_exception();
  }
}