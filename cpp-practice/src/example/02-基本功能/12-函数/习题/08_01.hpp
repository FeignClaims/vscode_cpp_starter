#include <string>
#include <string_view>

struct Tnode {
  std::string word;
  int count{1};
  Tnode* left{};
  Tnode* right{};
};

void push(Tnode* t, std::string_view words);
void print(const Tnode* t);
void print_sort(const Tnode* t);