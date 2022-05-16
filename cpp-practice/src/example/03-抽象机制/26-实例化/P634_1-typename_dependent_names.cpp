template <typename Container>
void fct(Container& c) {
  // STAR: 默认情况下，编译器假定依赖性名字不是类型名
  Container::value_type v1{c[7]};  //\! 编译器假定 value_type 不是类型名
  typename Container::value_type v2{c[9]};  //\; 显示说明 value_type 是类型
  auto v3 = c[11];                          //\; 让编译器推断
  // ...
}

// STAR: 引入类型别名来避免使用 typename 的尴尬
template <typename T>
using ValueType = typename T::value_type;

template <typename Container>
void fct2(Container& c) {
  ValueType<Container> v1{c[7]};
  // ...
}