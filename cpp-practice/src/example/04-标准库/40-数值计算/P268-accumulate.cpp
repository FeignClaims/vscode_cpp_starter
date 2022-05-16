#include <format>
#include <iostream>
#include <numeric>
#include <vector>

struct Record {
  // ...
  int unit_price;
  int number_of_units;
};

auto price(long val, const Record& r) -> long {
  return val + r.unit_price * r.number_of_units;
}

void f(const std::vector<Record>& v) {
  std::cout << std::format("Total value: {}\n",
                           std::accumulate(v.begin(), v.end(), 0, price));
}