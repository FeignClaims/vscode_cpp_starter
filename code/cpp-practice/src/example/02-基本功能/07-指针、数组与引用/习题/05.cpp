#include <cstdint>
#include <cstdlib>

auto def(int* a, int* b) -> std::int64_t {
  return std::abs(a - b);
}