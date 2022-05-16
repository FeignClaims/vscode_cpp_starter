#include <vector>
template <typename T>
class Container {
 public:
  void sort();  // 排序元素
                // ...
 private:
  std::vector<T> v;  // 元素
  // ...
};

//\* Container<int> 的实例化点
void f() {
  Container<int> c;  // 使用点
  c.sort();
}