#include <cstdint>

constexpr auto middle(int a) -> std::uint16_t {
  static_assert(sizeof(int) == 4, "unexpected int size");
  static_assert(sizeof(std::int16_t) == 2, "unexpected short size");
  return (a >> 8) & 0xFFFF;
}