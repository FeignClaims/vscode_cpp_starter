#include <cstring>

void copy1(const char* a, char* b) {
  size_t length{std::strlen(a)};
  for (size_t i{}; i <= length; ++i) {
    b[i] = a[i];
  }
}

void copy2(const char* a, char* b) {
  int i{};
  for (; a[i] != '\0'; ++i) {
    b[i] = a[i];
  }
  b[i] = 0;
}

void copy3(const char* a, char* b) {
  char* p{b};
  const char* q{a};
  while (*q != '\0') {
    *p = *q;
    ++q;
    ++p;
  }
  *p = '\0';
}

void copy4(const char* a, char* b) {
  char* p{b};
  const char* q{a};
  while (*q != '\0') {
    *p++ = *q++;
  }
  *p = '\0';
}

void copy5(const char* a, char* b) {
  char* p{b};
  const char* q{a};
  while ((*p++ = *q++) != '\0') continue;
}

void copy6(const char* a, char* b) {
  char* p{b};
  const char* q{a};
  while ((*p++ = *q++)) continue;
}