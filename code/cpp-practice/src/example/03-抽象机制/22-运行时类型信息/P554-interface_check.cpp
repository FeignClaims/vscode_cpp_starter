#include <istream>
#include <map>
#include <memory>
#include <sstream>
#include <stdexcept>
#include <string>

class IoObj {
 public:
  virtual ~IoObj() = default;

  [[nodiscard]] virtual auto clone() const -> IoObj*;  // 多态
};
template <typename T>
struct Io : IoObj {
  explicit Io(std::istream&);  // 从输入流初始化
  [[nodiscard]] auto clone() const -> Io* override { return new Io{*this}; }
  static auto new_io(std::istream& is) { return new Io{is}; }  // 供 io_map 使用

  T val;
};
class Shape {
 public:
  virtual ~Shape() = default;

  virtual void draw();
};
// 函数指针，指向的函数返回一个 IoObj*
using Pf = auto(std::istream&) -> IoObj*;
// 将字符串映射到相应的创建函数
auto io_map() -> std::map<std::string, Pf>& {
  static std::map<std::string, Pf> io_map;
  return io_map;
}
auto ss() -> std::istream& {
  static std::istringstream ss;
  return ss;
}
auto get_word(std::istream& is)
    -> std::string;  // 从 is 读取一个字，若读取失败抛出一个 ReadError
auto get_obj(std::istream&) -> IoObj* {
  std::string str{get_word(ss())};  // 读取起始字
  if (auto f = io_map()[str]) {     // 查找 str，获取对应函数
    return f(ss());                 // 调用函数
  }
  throw std::runtime_error{"Unknown class.\n"};  // map 中无匹配 str 的项
}

// STAR: 通过 dynamic_cast 确定对象是否是期望类型（提供了指定接口）
template <typename T>
auto get_val(IoObj* p) -> T* {
  if (auto pp = dynamic_cast<Io<T>*>(p)) {
    return &pp->val;
  }
  return nullptr;
}

void user() {
  // ... 打开文件，将 istream ss 与之关联，假定文件包含 Shape 对象
  std::unique_ptr<IoObj> p{get_obj(ss())};  // 从流中读取对象

  if (auto sp = get_val<Shape>(p.get())) {
    sp->draw();  // 使用 Shape
    // ...
  } else {
    //\$ 处理文件中非 Shape 对象
  }
}