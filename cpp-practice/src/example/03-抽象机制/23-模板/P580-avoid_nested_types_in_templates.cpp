// STAR: 在模板中尽量避免嵌入类型，除非它们真正依赖于所有模板参数
template <typename T>
class Link {
  template <typename U, typename A>
  friend class List;

  T val;
  Link* succ;
  Link* prev;
};

template <typename T>
struct Iterator {
  Link<T>* current_position;
};

template <typename T, typename A>
class List {
 public:
  auto begin() -> Iterator<T>;
  auto end() -> Iterator<T>;
};