#include "08_02.hpp"

#include <cstring>
#include <functional>
#include <iostream>
#include <set>
#include <string>
#include <utility>

void push(Tnode* t, const char* words) {
  if (!t) {
    t = new Tnode{words};
  }

  int res{std::strcmp(words, t->word)};
  if (res < 0) {
    push(t->left, words);
  } else if (res == 0) {
    ++t->count;
  } else {
    push(t->right, words);
  }
}

void print(const Tnode* t) {
  if (!t) return;

  std::cout << t->word << '\n';
  print(t->left);
  print(t->right);
}

void print_sort(const Tnode* t) {
  std::set<const char*> res;
  std::function<void(const Tnode*)> inset = [&](const Tnode* node) {
    if (!node) return;

    res.emplace(node->word);
    inset(node->left);
    inset(node->right);
  };
  for (const auto& x : res) {
    std::cout << x << '\n';
  }
}