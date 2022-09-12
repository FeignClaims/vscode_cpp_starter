class Pool {  // 某个分配器
 public:
  template <typename T>
  auto get() -> T*;

  template <typename T>
  void release(T*);
  // ...
};

template <typename Alloc>
void f(Alloc& all) {
  // STAR: 默认情况下，编译器假定依赖性名字的成员非模板
  int* p1{all.get<int>()};           //\! 编译器 get 是非模板名
  int* p2{all.template get<int>()};  //\; 编译器假定 get() 是一个模板
  // ...
}

void user(Pool& pool) {
  f(pool);
  // ...
}