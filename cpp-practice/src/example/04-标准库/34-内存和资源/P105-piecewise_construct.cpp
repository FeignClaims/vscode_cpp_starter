#include <string>
#include <utility>

struct Univ {
  Univ(std::string n, int r) : name{std::move(n)}, rank{r} {}
  std::string name;
  int rank;
  std::string city{"unknown"};
};

using Tup = std::tuple<std::string, int>;
Tup t1{"Columbia", 11};
Tup t2{"Cambridge", 2};

std::pair<Tup, Tup> p1{t1, t2};                              // tuple 的 pair
std::pair<Univ, Univ> p2{std::piecewise_construct, t1, t2};  // Univ 的 pair