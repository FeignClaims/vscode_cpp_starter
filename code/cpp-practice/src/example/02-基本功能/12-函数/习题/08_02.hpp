#include <string>

struct Tnode {
  const char* word;
  int count{1};
  Tnode* left{};
  Tnode* right{};
};

void push(Tnode* t, const char* words);
void print(const Tnode* t);
void print_sort(const Tnode* t);