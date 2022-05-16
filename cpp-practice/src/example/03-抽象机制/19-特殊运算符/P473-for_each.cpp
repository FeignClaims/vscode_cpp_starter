template <typename Iter, typename Fct>
auto for_each(Iter b, Iter e, Fct f) -> Fct {
  while (b != e) f(*b++);
  return f;
}