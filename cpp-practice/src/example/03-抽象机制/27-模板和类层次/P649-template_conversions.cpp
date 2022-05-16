template <typename T>
class Ptr {  // T 的指针
 public:
  explicit Ptr(T*);
  Ptr(const Ptr&);  // 拷贝构造函数

  template <typename T2>
  explicit operator Ptr<T2>();  // 将 Ptr<T> 转换为 Ptr<T2>

 private:
  T* p;
};

//\* 如果 T* 可以隐式转换为 T2*，则 Ptr<T> 可以转换为 Ptr<T2>
template <typename T>
template <typename T2>
Ptr<T>::operator Ptr<T2>() {
  return Ptr<T2>{p};
}

class Shape {};
class Circle : public Shape {};

void f(Ptr<Circle> pc) {
  Ptr<Shape> ps{pc};    //\; 可以将 Circle* 转换为 Shape*
  Ptr<Circle> pc2{ps};  //\! 不能将 Shape* 转换为 Circle*
}