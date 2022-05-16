template <typename T>
class Tree {
 public:
  void g(const T&);
  // ...

 private:
  using value_type = T;                  // 成员别名
  enum Policy { kRb, kSplay, kTreeps };  // 成员枚举
  class Node {
   public:
    void f(Tree*);

   private:
    Node* right;
    Node* left;
    value_type value;
  };
  Node* top;
};

template <typename T>
void Tree<T>::Node::f(Tree* p) {
  top = right;                 //\! 未指定类型为 Tree 的对象
  p->top = right;              // 正确
  value_type v = left->value;  // 正确：value_type 不与某个对象关联
}

template <typename T>
void Tree<T>::g(Tree::Node* p) {
  value_type val = right->value;   //\! 没有 Tree::Node 类型的对象
  value_type v = p->right->value;  //\! Node::right 是私有的
  p->f(this);                      // 正确
}