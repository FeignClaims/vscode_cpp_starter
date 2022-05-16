#include <vector>
template <typename N>
struct NodeBase : N::balance_type {  // 不了解 Val（用户数据）
  NodeBase();

  void insert(N* n) {
    if (this->compare(n, left_child)) {  // 使用来自 Balance 的 compare()
      // ... 进行某些操作 ...
    } else {
      // ... 进行某些操作 ...
    }
  }
  // ...

  N* left_child;
  N* right_child;
};

// star: CRTP（Curiously Recurring Template Pattern）
template <typename Val, typename Balance>
struct SearchNode
    : NodeBase<SearchNode<Val, Balance>> {  // 派生类作为其基类的一部分
  using balance_type = Balance;

  SearchNode(Val v) : val(v) {}
  // ...
  Val val;
};