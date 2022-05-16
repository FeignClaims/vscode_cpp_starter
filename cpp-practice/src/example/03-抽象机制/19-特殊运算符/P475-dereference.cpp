template <typename T>
class Ptr {
 public:
  // STAR: 解引用运算符（->，*，[]）的重载
  auto operator->() -> T* { return p; }  // 解引用以访问成员
  auto operator*() -> T& { return *p; }  // 解引用以访问整个对象
  auto operator[](int i) -> T& { return p[i]; }  // 解引用以访问元素

 private:
  T* p;
};