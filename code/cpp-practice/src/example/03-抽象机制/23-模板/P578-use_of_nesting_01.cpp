// star: 作为成员的 Link 只使用了 List 的两个模板参数其中之一，会导致代码膨胀
template <typename T, typename Allocator>
class List {
 private:
  struct Link {
    T val;
    Link* succ;
    Link* prev;
  };
  // ...
};