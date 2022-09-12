/**
 * 这是一种比较简单的字符串，它实现了短字符串优化
 *
 * size() == sz 是元素的个数
 * 如果 size() <= kShortMax 成立，则 String 对象自己保存字符；
 * 否则用自由存储保存。
 *
 * ptr 指向字符序列的起始处
 * 字符序列以 0 结尾：ptr[size()] == 0;
 * 这样设计的目的是便于我们使用 C 标准字符串函数以及返回 C 风格的字符串：
 *
 * c_str()
 * 为了便于在末尾添加字符，String 通常把它分配的空间扩充一倍；
 * capacity() 表示字符可用空间的总额（不包括结尾处的 0）：sz + space
 */

#include <cctype>
#include <cstring>
#include <iostream>
#include <stdexcept>

#include <corecrt.h>

// 扩展到自由存储
auto expand(const char* ptr, size_t n) -> char*;

class String {
 public:
  String();  // 默认构造函数：x{""}

  String(const char* p);  // 接受 C 风格字符串的构造函数：x{"Euler"}

  String(const String&);                           // 拷贝构造函数
  auto operator=(const String&) -> String&;        // 拷贝赋值
  String(String&& x) noexcept;                     // 移动构造函数
  auto operator=(String&& x) noexcept -> String&;  // 移动赋值

  ~String() {  // 析构函数
    if (kShortMax < sz_) delete[] ptr_;
  }

  auto operator[](size_t n) -> char& { return ptr_[n]; }  // 未经检查的元素访问
  auto operator[](size_t n) const -> char { return ptr_[n]; }

  auto at(int n) -> char& {
    check(n);
    return ptr_[n];
  }
  [[nodiscard]] auto at(int n) const -> char {
    check(n);
    return ptr_[n];
  }

  auto operator+=(char c) -> String&;  // 在末尾添加 c

  auto c_str() -> char* { return ptr_; }  // C 风格字符串的访问
  [[nodiscard]] auto c_str() const -> const char* { return ptr_; }

  [[nodiscard]] auto size() const -> size_t { return sz_; }  // 元素数量
  [[nodiscard]] auto capacity() const -> size_t {  // 元素以及可用空间（总容量）
    return (sz_ <= kShortMax) ? kShortMax : sz_ + space_;
  }

 private:
  void check(size_t n) const {  // 边界检查
    if (n < 0 || sz_ <= n) {
      throw std::out_of_range("String::at()");
    }
  }
  void copy_from(const String& x);
  void move_from(String& x);

  static const size_t kShortMax{15};
  size_t sz_{};  // 字符数量
  char* ptr_;
  union {
    size_t space_;            // 未使用的已分配空间
    char ch_[kShortMax + 1];  // 为结尾的 0 预留空间
  };
};

auto operator<<(std::ostream& os, const String& s) -> std::ostream&;
auto operator>>(std::istream& is, String& s) -> std::istream&;

auto operator==(const String& a, const String& b) -> bool;
auto operator!=(const String& a, const String& b) -> bool;

auto begin(String& x) -> char* {  // C 风格字符串的访问
  return x.c_str();
}
auto end(String& x) -> char* {
  return x.c_str() + x.size();
}
auto begin(const String& x) -> const char* {
  return x.c_str();
}
auto end(const String& x) -> const char* {
  return x.c_str() + x.size();
}

auto operator+=(String& a, const String& b) -> String& {  // 链接
  for (auto x : b) {
    a += x;
  }
  return a;
}
auto operator+=(const String& a, const String& b) -> String {  // 链接
  String res{a};
  res += b;
  return res;
}

auto operator""_s(const char* p, size_t) {
  return String{p};
}