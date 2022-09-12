#include <set>
#include <vector>

class Entry {};
class Record {};

template <typename T, template <typename> class C>
class Xrefd {
  C<T> mems;
  C<T*> refs;
  // ...
};

template <typename T>
using MyVec = std::vector<T>;  // 使用默认分配器

Xrefd<Entry, MyVec> x1;  // 在 std::vector 中存储 Entry 的交叉引用

template <typename T>
class MyContainer {
  // ...
};

Xrefd<Record, MyContainer> x2;  // 在 MyContainer 中存储 Records 的交叉引用

// star: 对于模板需要一两个容器这种常见的情形
//\* 其实没有必要使用模板作为实参，传递容器类型是更好的方式
template <typename C, typename C2>
class Xrefd2 {
  C mems;
  C2 refs;
  // ...
};

Xrefd2<std::vector<Entry>, std::set<Entry*>> x;