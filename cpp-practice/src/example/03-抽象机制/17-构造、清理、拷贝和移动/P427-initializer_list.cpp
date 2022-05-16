#include <initializer_list>
#include <iostream>

void f(std::initializer_list<int> args) {
  for (size_t i{}; i != args.size(); ++i) {
    std::cout << args.begin()[i] << '\n';
  }
}

void g(std::initializer_list<int> args) {
  for (auto p = args.begin(); p != args.end(); ++p) {
    std::cout << *p << '\n';
  }
}

void h(std::initializer_list<int> args) {
  for (auto x : args) {
    std::cout << x << '\n';
  }
}