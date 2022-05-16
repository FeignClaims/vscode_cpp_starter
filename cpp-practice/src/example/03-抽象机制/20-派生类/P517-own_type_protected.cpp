class Buffer {
 protected:
  char a[128];
  // ...
};

class LinkedBuffer : public Buffer {
  // ...
};

// STAR: 一个派生类只能对自身类型的对象访问其基类的保护成员
class CircularBuffer : public Buffer {
  // ...
  void f(LinkedBuffer* p) {
    a[0] = 0;     //\; 访问 CircularBuffer 自己的保护成员
    p->a[0] = 0;  //\! 访问不同类型的保护成员
  }
};