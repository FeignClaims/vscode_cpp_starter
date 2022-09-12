#ifndef MATRIX_IMPL_HPP
#define MATRIX_IMPL_HPP

#include "P713_1-slice.hpp"

#include <algorithm>
#include <array>
#include <cassert>
#include <concepts>
#include <cstddef>
#include <functional>
#include <initializer_list>
#include <numeric>
#include <type_traits>

template <size_t N>
struct MatrixSlice {
  MatrixSlice() = default;  // 空矩阵：无元素
  MatrixSlice(std::size_t s,
              std::initializer_list<std::size_t> exts);  // 维度大小
  MatrixSlice(std::size_t s,
              std::initializer_list<std::size_t> exts,
              std::initializer_list<std::size_t> strs);  // 维度大小和跨距

  template <std::convertible_to<std::size_t>... Dims>  // N 个维度大小
  explicit MatrixSlice(Dims... dims);

  auto operator()(std::convertible_to<std::size_t> auto... dims) const
      -> std::size_t;  // 从一组下标计算索引

  std::size_t size{};                  // 元素总数
  std::size_t start{};                 // 起始偏移量
  std::array<std::size_t, N> extents;  // 每个维度大小
  std::array<std::size_t, N> strides;  // 每个维度上元素间的偏移量
};

template <std::size_t N>
inline auto MatrixSlice<N>::operator()(
    std::convertible_to<std::size_t> auto... dims) const -> std::size_t {
  static_assert(sizeof...(dims) == N);
  std::array<std::size_t, N> args{
      std::size_t(dims)...};  // 将实参拷贝到一个数组中
  return std::inner_product(args, args + N, strides.begin(), std::size_t{0});
}

template <std::size_t N, typename T, typename... Args>
auto do_slice(const MatrixSlice<N>& os,
              MatrixSlice<N>& ns,
              const T& s,
              const Args&... args) -> std::size_t {
  std::size_t m = do_slice_dim<sizeof...(Args) + 1>(os, ns, s);
  std::size_t n = do_slice(os, ns, args...);
  return m + n;
}
template <std::size_t N>
auto do_slice(const MatrixSlice<N>&, MatrixSlice<N>&) -> std::size_t {
  return 0;
}

template <typename T, std::size_t N>
class MatrixRef {
 public:
  MatrixRef(const MatrixSlice<N>& s, T* p) : desc_{s}, ptr_{p} {}

  // ... 很像 Matrix...

 private:
  MatrixSlice<N> desc_;  // 矩阵形状
  T* ptr_;               // 指向矩阵的第一个元素
};

template <typename T, std::size_t N>
class MatrixInit {
 public:
  using type = std::initializer_list<typename MatrixInit<T, N - 1>::type>;
};
template <typename T>
class MatrixInit<T, 1> {
 public:
  using type = std::initializer_list<T>;
};
template <typename T>
class MatrixInit<T, 0>;  // 故意设置为未定义的

template <typename T, std::size_t N>
using MatrixInitializer = typename MatrixInit<T, N>::type;

template <typename List>
auto check_non_jagged(const List& list) {
  auto i = list.begin();
  for (auto j = i + 1; j != list.end(); ++j) {
    if (i->size() != j->size()) return false;
  }
  return true;
}

template <std::size_t N, typename I, typename List>
void add_extents(I& first, const List& list) {
  assert(check_non_jagged(list));
  *first = list.size();
  add_extents<N - 1>(++first, *list.begin());
}
template <std::size_t N, typename I, typename List>
void add_extents(I& first, const List& list) requires(N == 1) {
  *first++ = list.size();  // 达到最深嵌套层
}

template <std::size_t N, typename List>
auto derive_extents(const List& list) -> std::array<std::size_t, N> {
  std::array<std::size_t, N> a;
  auto f = a.begin();
  add_extents<N>(f, list);  // 将维度大小添加到 a 中
  return a;
}

template <typename T, typename Vec>  // 嵌套的 initializer_list
void add_list(const std::initializer_list<T>* first,
              const std::initializer_list<T>* last,
              Vec& vec) {
  for (; first != last; ++first) {
    add_list(first->begin(), first->end(), vec);
  }
}
template <typename T, typename Vec>
void add_list(const T* first, const T* last, Vec& vec) {
  vec.insert(vec.end(), first, last);
}

template <typename T, typename Vec>
void insert_flat(std::initializer_list<T> list, Vec& vec) {
  add_list(list.begin(), list.end(), vec);
}

template <std::size_t N>
auto check_bounds(const MatrixSlice<N>& slice,
                  std::convertible_to<std::size_t> auto... dims) {
  std::array<std::size_t, N> indexes{std::size_t(dims)...};
  return std::equal(
      indexes, indexes + N, slice.extents, std::less<std::size_t>{});
}

template <typename T>
concept RequestingElement = std::convertible_to<T, std::size_t>;

template <typename T>
concept RequestingSlice =
    std::convertible_to<T, std::size_t> || std::same_as<T, slice>;

#endif