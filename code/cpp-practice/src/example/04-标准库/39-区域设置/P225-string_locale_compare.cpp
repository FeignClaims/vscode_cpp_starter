#include <locale>
#include <string>

void f1(const std::string& s1, const std::string& s2, const std::string& name) {
  bool b{s1 == s2};  // 用 C++ 实现的字符集值进行比较

  const auto* s1b = s1.data();              // 获得数据的起始位置
  const auto* s1e = s1.data() + s1.size();  // 获得数据的结束位置
  const auto* s2b = s2.data();
  const auto* s2e = s2.data() + s2.size();
  using Col = std::collate<char>;

  const Col& global{std::use_facet<Col>(std::locale{})};  // 来自当前全局 locale
  int i0{global.compare(s1b, s1e, s2b, s2e)};

  const Col& my_coll{
      std::use_facet<Col>(std::locale{""})};  // 来自我优选的 locale
  int i1{my_coll.compare(s1b, s1e, s2b, s2e)};

  const Col& n_coll{
      std::use_facet<Col>(std::locale{name})};  // 来自一个命名 locale
  int i2{n_coll.compare(s1b, s1e, s2b, s2e)};
  // ...
}

// star: 通过 locale 的 operator() 间接使用 collate 的 compare() 可能更为方便
void f(const std::string& s1, const std::string& s2, const std::string& name) {
  int i0{std::locale{}(s1, s2)};      // 使用当前全局 locale 进行比较
  int i1{std::locale{""}(s1, s2)};    // 使用我优选的 locale 进行比较
  int i2{std::locale{name}(s1, s2)};  // 使用命名 locale 进行比较
  // ...
}