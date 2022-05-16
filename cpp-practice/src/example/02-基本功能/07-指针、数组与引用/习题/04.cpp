#include <cstdint>
#include <cstdlib>

auto def(char* a, char* b) -> std::int64_t {
  return std::abs(a - b);
}