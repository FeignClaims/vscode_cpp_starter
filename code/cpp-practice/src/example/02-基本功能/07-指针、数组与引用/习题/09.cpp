void f(char);
void g(char&);
void h(const char&);

auto main() -> int {
  char c{};
  unsigned char uc{};
  signed char sc{};

  f('a');
  f(49);
  f(3300);
  f(c);
  f(uc);
  f(sc);

  g('a');
  g(49);
  g(3300);
  g(c);
  g(uc);
  g(sc);

  h('a');
  h(49);
  h(3300);
  h(c);
  h(uc);
  h(sc);
}