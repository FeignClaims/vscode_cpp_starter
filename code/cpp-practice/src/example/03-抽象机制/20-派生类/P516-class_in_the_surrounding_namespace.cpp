namespace anamespace {
// STAR: 访问控制：将类型放在包含类的名字空间中
template <typename T>
struct Link2 {
  T val;
  Link2* next;
};

template <typename T>
class List {
 private:
  Link2<T>* free_;
  // ...
};
}  // namespace anamespace