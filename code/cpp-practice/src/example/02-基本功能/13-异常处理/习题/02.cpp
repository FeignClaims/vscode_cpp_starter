#include <cstring>

struct Node {
  const char* str;
  Node* left;
  Node* right;
};

struct NotFound {};

auto find(const char* obj, Node* node) -> Node* {
  if (!node) {
    throw NotFound{};
  }

  int cmp{std::strcmp(obj, node->str)};
  if (cmp == 0) {
    return node;
  }
  if (cmp < 0) {
    return find(obj, node->left);
  }
  if (cmp > 0) {
    return find(obj, node->right);
  }
}