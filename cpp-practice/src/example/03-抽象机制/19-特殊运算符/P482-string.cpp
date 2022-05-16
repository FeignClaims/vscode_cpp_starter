#include "P482-string.hpp"

auto expand(const char* ptr, size_t n) -> char* {  // 扩展到自由存储
  char* p{new char[n]};
  std::strcpy(p, ptr);  // 见 43.4 节
  return p;
}

String::String()
    : ptr_{ch_},  // ptr 指向元素，ch 是初始位置
      ch_{0}      // 以 0 结尾
{
}

String::String(const char* p)
    : sz_{std::strlen(p)}, ptr_{(sz_ <= kShortMax) ? ch_ : new char[sz_ + 1]} {
  std::strcpy(ptr_, p);
}

String::String(const String& x) {  // 拷贝构造函数
  copy_from(x);                    // 从 x 中拷贝其表示部分
}

String::String(String&& x) noexcept {  // 移动构造函数
  move_from(x);
}

auto String::operator=(const String& x) -> String& {
  if (this == &x) return *this;  // 处理自赋值
  char* p{(kShortMax < sz_) ? ptr_ : nullptr};
  copy_from(x);
  delete[] p;
  return *this;
}

auto String::operator=(String&& x) noexcept -> String& {
  if (this == &x) return *this;  // 处理自赋值（x = move(x) 看起来了不合常理）
  if (kShortMax < sz_) delete[] ptr_;  // 使用 delete 删除目标
  move_from(x);                        // 不抛出异常
  return *this;
}

auto String::operator+=(char c) -> String& {
  if (sz_ == kShortMax) {     // 扩展到长字符串
    size_t n{(sz_ + 1) * 2};  // 把空间扩充一倍
    ptr_ = expand(ptr_, n);
    space_ = n - sz_ - 2;
  } else if (kShortMax < sz_) {
    if (space_ == 0) {          // 在自由存储上扩充
      size_t n{(sz_ + 1) * 2};  // 把空间扩充一倍
      char* p{expand(ptr_, n)};
      delete[] ptr_;
      ptr_ = p;
      space_ = n - sz_ - 2;
    } else {
      --space_;
    }
  }
  ptr_[sz_] = c;    // 在末尾添加 c
  ptr_[++sz_] = 0;  // 增加长度并设置结束符

  return *this;
}

void String::copy_from(const String& x) {
  if (x.sz_ <= kShortMax) {       // 拷贝 *this
    memcpy(this, &x, sizeof(x));  // 见 43.5 节
    ptr_ = ch_;
  } else {  // 拷贝元素
    ptr_ = expand(x.ptr_, sz_ + 1);
    sz_ = x.sz_;
    space_ = 0;
  }
}

void String::move_from(String& x) {
  if (x.sz_ <= kShortMax) {       // 拷贝 *this
    memcpy(this, &x, sizeof(x));  // 见 43.5 节
    ptr_ = ch_;
  } else {  // 移动元素
    ptr_ = x.ptr_;
    sz_ = x.sz_;
    space_ = x.space_;
    x.ptr_ = x.ch_;  // x = ""
    x.sz_ = 0;
    x.ch_[0] = 0;
  }
}

auto operator<<(std::ostream& os, const String& s) -> std::ostream& {
  return os << s.c_str();  // 见 36.3.3 节
}

auto operator>>(std::istream& is, String& s) -> std::istream& {
  s = "";         // 清空目标串
  is >> std::ws;  // 跳过空白（见 38.4.1.1 节和 38.4.5.2 节）
  char ch{' '};
  while (is.get(ch) && !std::isspace(ch)) {
    s += ch;
  }
  return is;
}

auto operator==(const String& a, const String& b) -> bool {
  if (a.size() != b.size()) {
    return false;
  }
  for (size_t i{}; i < a.size(); ++i) {
    if (a[i] != b[i]) {
      return false;
    }
  }
  return true;
}

auto operator!=(const String& a, const String& b) -> bool {
  return !(a == b);
}