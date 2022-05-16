// STAR: 内部程序表示（Internal Program Representation, IPR）

namespace ipr {  // interface
struct Node {
  virtual ~Node() = 0;
  // ...
};
struct Expr : Node {
  // ...
};
struct Stmt : Expr {
  // ...
};
struct Decl : Stmt {
  // ...
};
struct Var : Decl {
  // ...
};
}  // namespace ipr

namespace impl {  // concrete class
template <typename T>
struct Node : T {  // star: the T will be "ipr::Var"
  // ...
};
template <typename T>
struct Expr : Node<T> {
  // ...
};
template <typename S>
struct Stmt : Expr<S> {
  // ...
};
template <typename D>
struct Decl : Stmt<D> {
  // ...
};
struct Var : Decl<ipr::Var> {  // star: set to "ipr::Var"
  // ...
};
}  // namespace impl