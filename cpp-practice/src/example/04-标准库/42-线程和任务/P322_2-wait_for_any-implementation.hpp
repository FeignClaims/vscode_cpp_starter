#include <chrono>
#include <future>
#include <stdexcept>
#include <thread>
#include <vector>

#include <__utility/cmp.h>

// 返回就绪的 future 的索引
// 如无 future 就绪，等待时长 d 之后再尝试
template <typename T>
auto wait_for_any(std::vector<std::future<T>>& vf,
                  std::chrono::steady_clock::duration d) -> int {
  while (true) {
    for (int i{}; std::cmp_less(i, vf.size()); ++i) {
      if (!vf[i].valid()) continue;
      //\* 用 future.wait_for(seconds{0}) 检查 future 是否就绪
      //\* wait_for() 会告诉我们它为什么恢复，并在暂停之前检测是否就绪
      switch (vf[i].wait_for(std::chrono::seconds{0})) {
        case std::future_status::ready:
          return i;
        case std::future_status::timeout:
          break;
        case std::future_status::deferred:
          throw std::runtime_error{"wait_for_all(): deferred future"};
      }
    }
    std::this_thread::sleep_for(d);
  }
}