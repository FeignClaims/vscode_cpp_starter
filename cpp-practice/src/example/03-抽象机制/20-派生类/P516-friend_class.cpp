template <typename T>
class List;

template <typename T>
class Link3 {
 private:
  // STAR: 访问控制：友元类
  friend class List<T>;  // 只有 List<T> 能访问 Link3<T>
  T val_;
  Link3* next_;
};

template <typename T>
class List {
 private:
  Link3<T>* free_;
  // ...
};