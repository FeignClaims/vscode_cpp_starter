#ifndef SLICE_HPP
#define SLICE_HPP

#include <cstddef>
#include <numeric>

struct slice {
  explicit slice(std::size_t s) : start{s} {}
  slice(std::size_t s, std::size_t l, std::size_t n = 1)
      : start{s}, length{l}, stride{n} {}

  auto operator()(std::size_t i) const -> std::size_t {
    return start + i * stride;
  }

  static slice all;

  std::size_t start{kDefaultValue};  // 第一个索引
  std::size_t length{kDefaultValue};  // 包含的索引数目（可用于范围检查）
  std::size_t stride{1};              // 序列中元素间的距离
 private:
  static constexpr auto kDefaultValue{std::numeric_limits<std::size_t>::max()};
};

#endif