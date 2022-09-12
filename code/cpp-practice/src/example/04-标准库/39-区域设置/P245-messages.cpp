#include <compare>
#include <cstddef>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <locale>
#include <string>
#include <vector>

struct Set {
  std::vector<std::string> msgs;
};

struct Cat {
  std::vector<Set> sets;
};

class MyMessages : public std::messages<char> {
 public:
  explicit MyMessages(std::size_t /*unused*/ = {})
      : catalogs{*new std::vector<Cat>} {}

  ~MyMessages() override { delete &catalogs; }

  [[nodiscard]] auto do_open(const std::string& n, const std::locale& loc) const
      -> catalog override;  // 打开 s
  [[nodiscard]] auto do_get(catalog cat,
                            int s,
                            int m,
                            const std::string& /*def*/) const
      -> std::string override;  // 获取 cat 中的消息（s,m）
  void do_close(catalog cat) const override {
    if (std::cmp_less_equal(catalogs.size(), cat)) {
      catalogs.erase(catalogs.begin() + cat);
    }
  }

 private:
  std::vector<Cat>& catalogs;
};

auto MyMessages::do_get(catalog cat,
                        int set,
                        int msg,
                        const std::string& def) const -> std::string {
  if (std::cmp_less_equal(catalogs.size(), cat)) {
    return def;
  }
  auto& c = catalogs[cat];
  if (std::cmp_less_equal(c.sets.size(), set)) {
    return def;
  }
  auto& s = c.sets[set];
  if (std::cmp_less_equal(s.msgs.size(), msg)) {
    return def;
  }
  return s.msgs[msg];
}

auto MyMessages::do_open(const std::string& n, const std::locale& /*loc*/) const
    -> std::messages<char>::catalog {
  auto nn = n + std::locale().name();
  std::ifstream f(nn.c_str());
  if (!f) return -1;

  catalogs.push_back(Cat{});  // 创建核心目录
  auto& c = catalogs.back();

  for (std::string s; f >> s && s == "<<<";) {  // 读取 Set
    c.sets.push_back(Set{});
    auto& ss = c.sets.back();
    while (std::getline(f, s) && s != ">>>") {  // 读取消息
      ss.msgs.push_back(s);
    }
  }
  return catalogs.size() - 1;
}

auto main() -> int {  // 一个简单测试
  if (!std::has_facet<MyMessages>(std::locale{})) {
    std::cerr << "no messages facet found in" << std::locale{}.name() << '\n';
    std::exit(1);
  }

  const auto& m = std::use_facet<MyMessages>(std::locale{});
  extern std::string message_directory;  // 我保存消息的地方

  auto cat = m.open(message_directory, std::locale{});
  if (cat < 0) {
    std::cerr << "no catalog found\n";
    std::exit(1);
  }

  std::cout << m.get(cat, 0, 0, "Missed again!") << std::endl;
  std::cout << m.get(cat, 1, 2, "Missed again!") << std::endl;
  std::cout << m.get(cat, 1, 3, "Missed again!") << std::endl;
  std::cout << m.get(cat, 3, 0, "Missed again!") << std::endl;
}