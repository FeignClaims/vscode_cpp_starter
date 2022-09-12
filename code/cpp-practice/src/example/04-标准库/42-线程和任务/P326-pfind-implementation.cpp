#include "P322_2-wait_for_any-implementation.hpp"

#include <algorithm>
#include <cassert>
#include <chrono>
#include <concepts>
#include <future>
#include <vector>

struct Record {};

constexpr int kGrain{50000};  // 线性搜索的记录数

auto find_rec(std::vector<Record>& vr,
              int first,
              int last,
              std::predicate<const Record&> auto pr) {
  auto p = std::find_if(vr.begin() + first, vr.begin() + last, pr);
  if (p == vr.begin() + last) {
    return nullptr;  // 到达末尾：未找到记录
  }
  return &*p;  // 找到：返回指向元素的指针
}

auto pfind(std::vector<Record>& vr, std::predicate<const Record&> auto pr)
    -> Record* {
  assert(vr.size() % kGrain == 0);

  std::vector<std::future<Record*>> res;

  for (std::size_t i{}; i < vr.size(); i += kGrain) {
    res.push_back(std::async(find_rec, std::ref(vr), i, i + kGrain, pr));
  }

  // star: 版本一，按顺序等待任务完成
  for (std::size_t i{}; i < res.size(); ++i) {  // 在 futures 中查找结果
    if (auto* p = res[i].get()) {  // 此任务找到匹配结果了吗？
      return p;
    }
  }

  return nullptr;  // 未找到匹配结果
}

auto pfind_any(std::vector<Record>& vr, std::predicate<const Record&> auto pr)
    -> Record* {
  assert(vr.size() % kGrain == 0);

  std::vector<std::future<Record*>> res;

  for (std::size_t i{}; i < vr.size(); i += kGrain) {
    res.push_back(std::async(find_rec, std::ref(vr), i, i + kGrain, pr));
  }

  // star: 版本二，按任务完成的顺序查看结果
  for (std::size_t count{res.size()}; count != 0; --count) {
    int i{wait_for_any(res, std::chrono::microseconds{10})};  // 某个任务完成
    if (auto* p = res[i].get()) {  // 此任务找到匹配结果了吗？
      return p;
    }
  }

  return nullptr;  // 未找到匹配结果
}