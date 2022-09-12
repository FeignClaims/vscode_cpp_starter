#include <format>
#include <iostream>
#include <map>
#include <string>
#include <utility>

auto main() -> int {
  std::map<std::string, std::string> dictionary;

  dictionary["sea"] = "large body of water";  // 插入元素或向元素赋值

  std::cout << std::format(
      "{}\n",
      dictionary["seal"]);  // 读取值，如果未找到关键字 k，会插入 (k, V{})

  if (auto q = dictionary.find("seal");
      q == dictionary.end()) {  // 查找关键字：不会插入新元素
    std::cout << std::format("entry not found\n");
    dictionary.insert(std::make_pair("seal", "eats fish"));
  } else {
    std::cout << std::format("{}\n", q->second);
  }
}