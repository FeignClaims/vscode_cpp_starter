#include <iostream>
enum Type { kStr, kNum };

union Value {
  char* s;
  int i;
};

struct Entry {
  char* name;
  Type t;
  Value v;
};

void f(Entry* p) {
  if (p->t == kStr) {
    std::cout << p->v.s;
  }
}