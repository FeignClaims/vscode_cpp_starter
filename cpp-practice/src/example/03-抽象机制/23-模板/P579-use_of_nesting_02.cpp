template <typename T, typename Allocator>
class List;

template <typename T>
class Link {
  // STAR: 声明模板友元
  template <typename U, typename A>
  friend class List;

  T val;
  Link* succ;
  Link* prev;
};

// star: Iterator 形式上依赖于 Allocator，不能使用而与其无关
template <typename T, typename Allocator>
class List {
  class Iterator {
   public:
    // ...常用的迭代器操作...
   private:
    Link<T>* current_position;
  };

  auto begin() -> Iterator;
  auto end() -> Iterator;
};