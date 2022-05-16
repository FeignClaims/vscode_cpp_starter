#include "08_01.hpp"

#include <functional>
#include <iostream>
#include <set>
#include <string>
#include <utility>

void push(Tnode* t, const std::string& words) {
  if (!t) {
    t = new Tnode{words};
  }

  if (words < t->word) {
    push(t->left, words);
  } else if (words == t->word) {
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
  std::set<std::string> res;
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