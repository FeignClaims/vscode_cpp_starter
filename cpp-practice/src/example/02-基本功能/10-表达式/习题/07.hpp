#include <cstddef>
#include <stdexcept>

auto mystrlen(const char* str) -> std::size_t {
  int i{};
  while (str[i] != '\0') {
    ++i;
  }
  return i;
}

void mystrcpy(const char* a, char* b) {
  while ((*b++ = *a++)) continue;
}

auto mystrcmp(const char* a, char* b) -> int {
  char* p{b};
  const char* q{a};
  while ((*p++ = *q++)) continue;
}