#include <typeinfo>

class Shape {};

void f(Shape& r, Shape* p) {
  typeid(r);   // 获得 r 引用的对象的类型
  typeid(*p);  // 获得 p 指向的对象的类型
  typeid(p);  //\$ 获得指针的类型，即 Shape*（这种用法不常见，通常是用错了）
}