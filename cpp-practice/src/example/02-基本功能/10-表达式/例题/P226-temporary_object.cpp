#include <iostream>
#include <string>

// STAR: 临时对象的生命周期
void f(std::string& s1, std::string& s2, std::string& s3) {
  const char* cs{
      (s1 + s2)
          .c_str()};  // alert: cs 指向临时 string 对象引出的 C 风格字符串指针
  std::cout << cs;
  if (strlen(cs = (s2 + s3).c_str()) < 8 && cs[0] == 'a') {
    // alert: 使用 cs，但进入受控语句之前，临时 string 对象已经被销毁
  }
}

void g(std::string& s1, std::string& s2, std::string& s3) {
  std::cout << s1 + s2;
  std::string s{s2 + s3};
  if (s.size() < 8 && s[0] == 'a') {
    // 使用 s
  }
}