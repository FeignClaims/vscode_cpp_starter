#ifndef MATRIX_HPP
#define MATRIX_HPP

#include "P713_2-matrix_impl.hpp"

#include <cassert>
#include <concepts>
#include <cstddef>
#include <initializer_list>
#include <numeric>
#include <type_traits>
#include <vector>

template <typename M>
concept MatrixType = requires(M m) {
  m;
};

template <typename T>
using ValueType = typename T::value_type;

template <typename T, std::size_t N>
class Matrix {
 public:
  using value_type = T;
  using iterator = typename std::vector<T>::iterator;
  using const_iterator = typename std::vector<T>::const_iterator;

  static constexpr std::size_t kOrder = N;

  Matrix() = default;
  Matrix(const Matrix&) = default;
  auto operator=(const Matrix&) -> Matrix& = default;
  Matrix(Matrix&&) noexcept = default;
  auto operator=(Matrix&&) noexcept -> Matrix& = default;

  template <std::convertible_to<T> U>
  explicit Matrix(const MatrixRef<U, N>&);  // 从 MatrixRef 构造
  template <std::convertible_to<T> U>
  auto operator=(const MatrixRef<U, N>&) -> Matrix&;  // 从 MatrixRef 赋值

  template <typename... Exts>  // 指明每一维的大小
  explicit Matrix(Exts... exts);

  explicit Matrix(MatrixInitializer<T, N>);            // 列表初始化
  auto operator=(MatrixInitializer<T, N>) -> Matrix&;  // 列表赋值

  template <typename U>
  Matrix(std::initializer_list<U>) = delete;
  template <typename U>
  auto operator=(std::initializer_list<U>) -> Matrix& = delete;

  ~Matrix() = default;

  static constexpr auto order() -> std::size_t { return N; }  // 维数
  [[nodiscard]] auto extent(std::size_t n) const -> std::size_t {
    return desc_.extents[n];
  }  // 第 n 维元素数
  [[nodiscard]] auto size() const -> std::size_t {
    return elems_.size();
  }  // 元素总数
  [[nodiscard]] auto descriptor() const -> const MatrixSlice<N>& {
    return desc_;
  }  // 定义下标操作的切片

  auto data() -> T* { return elems_.data(); }  // “平坦”元素访问
  auto data() const -> const T* { return elems_.data(); }

  auto operator()(RequestingElement auto... args)
      -> T&;  // m(i, j, k) 用整数进行下标操作
  auto operator()(RequestingElement auto... args) const -> T&;

  auto operator()(const RequestingSlice auto&... args)
      -> MatrixRef<T, N>;  // m(s1, s2, s3) 用切片进行下标操作
  auto operator()(const RequestingSlice auto&... args) const -> MatrixRef<T, N>;

  auto operator[](std::size_t i) -> MatrixRef<T, N - 1> {  // m[i] 行访问
    return row(i);
  }
  auto operator[](std::size_t i) const -> MatrixRef<const T, N - 1> {
    return row(i);
  }

  auto row(std::size_t n) -> MatrixRef<T, N - 1>;  // 行访问
  [[nodiscard]] auto row(std::size_t n) const -> MatrixRef<const T, N - 1>;

  auto col(std::size_t n) -> MatrixRef<T, N - 1>;  // 列访问
  [[nodiscard]] auto col(std::size_t n) const -> MatrixRef<const T, N - 1>;

  auto apply(std::invocable<T> auto f) -> Matrix&;  // 对每个元素 x 执行 f(x)

  auto apply(MatrixType auto& m,
             std::invocable<T, ValueType<decltype(m)>> auto f)
      -> Matrix&;  // 对特定元素执行 f(x, mx)

  auto operator=(const T& value) -> Matrix&;  // 用标量赋值

  auto operator+=(const T& value) -> Matrix&;  // 标量加
  auto operator-=(const T& value) -> Matrix&;  // 标量减
  auto operator*=(const T& value) -> Matrix&;  // 标量乘
  auto operator/=(const T& value) -> Matrix&;  // 标量除
  auto operator%=(const T& value) -> Matrix&;  // 标量模

  auto operator+=(const MatrixType auto& x) -> Matrix&;  // 矩阵加
  auto operator-=(const MatrixType auto& x) -> Matrix&;  // 矩阵减

  // ...

 private:
  MatrixSlice<N> desc_;   // 定义 N 个维度大小的切片
  std::vector<T> elems_;  // 元素
};

template <typename T>
class Matrix<T, 0> {
 public:
  static constexpr std::size_t order{0};
  using value_type = T;

  explicit Matrix(const T& x) : elem_{x} {}
  auto operator=(const T& value) -> Matrix& {
    elem_ = value;
    return *this;
  }

  auto operator()() -> T& { return elem_; }
  auto operator()() const -> const T& { return elem_; }

  explicit operator T&() { return elem_; }
  explicit operator const T&() { return elem_; }

 private:
  T elem_;
};

template <typename T, std::size_t N>
template <typename... Exts>
inline Matrix<T, N>::Matrix(Exts... exts)
    : desc_{exts...}, elems_{desc_.size()} {
}

template <typename T, std::size_t N>
inline Matrix<T, N>::Matrix(MatrixInitializer<T, N> init) {
  derive_extents(init, desc_.extents);  // 从初始化器推断维度大小
  elems_.reserve(desc_.size);           // 为切片留出空间
  insert_flat(init, elems_);            // 用初始化器列表进行初始化
  assert(elems_.size() == desc_.size);
}

template <typename T, std::size_t N>
template <std::convertible_to<T> U>
inline Matrix<T, N>::Matrix(const MatrixRef<U, N>& x)
    : desc_{x.desc_}, elems_{x.begin(), x.end()} {  // 拷贝 desc_ 和元素
}

template <typename T, std::size_t N>
template <std::convertible_to<T> U>
inline auto Matrix<T, N>::operator=(const MatrixRef<U, N>& x) -> Matrix& {
  desc_ = x.desc_;
  elems_.assign(x.begin(), x.end());
  return *this;
}

template <typename T, std::size_t N>
inline auto Matrix<T, N>::apply(std::invocable<T> auto f) -> Matrix& {
  for (auto& x : elems_) f(x);  // 次循环使用跨越式迭代器
  return *this;
}
template <typename T, std::size_t N>
inline auto Matrix<T, N>::apply(
    MatrixType auto& m, std::invocable<T, ValueType<decltype(m)>> auto f)
    -> Matrix& {
  assert(same_extents(desc_, m.descriptor()));  // 确保大小匹配
  for (auto i{begin()}, j{m.begin()}; i != end(); ++i, ++j) {
    f(*i, *j);
    return *this;
  }
}

template <typename T, std::size_t N>
inline auto Matrix<T, N>::operator+=(const T& val) -> Matrix<T, N>& {
  return apply([&](T& a) { a += val; });  // 使用了 lambda
}

template <typename T, std::size_t N>
inline auto operator+(const Matrix<T, N>& m, const T& val) -> Matrix<T, N> {
  auto res = m;
  res += val;
  return res;
}
template <typename T, std::size_t N>
inline auto operator+(const T& val, const Matrix<T, N>& m) -> Matrix<T, N> {
  auto res = m;
  res += val;
  return res;
}

template <typename T, std::size_t N>
inline auto Matrix<T, N>::operator+=(const MatrixType auto& m) -> Matrix& {
  static_assert(m.order() == N, "+=: mismatched Matrix dimensions");
  assert(same_extents(desc_, m.descriptor()));  // 确保大小匹配

  return apply(m, [](T& a, ValueType<decltype(m)>& b) { a += b; });
}
template <
    typename T1,
    typename T2,
    std::size_t N,
    typename RT = Matrix<std::common_type_t<ValueType<T1>, ValueType<T2>>, N>>
inline auto operator+(const Matrix<T1, N>& a, const Matrix<T2, N>& b)
    -> Matrix<RT, N> {
  auto res = a;
  res += b;
  return res;
}

template <typename T, std::size_t N>
inline auto operator+(const MatrixRef<T, N>& x, const T& n) -> Matrix<T, N> {
  Matrix<T, N> res{x};
  res += n;
  return res;
}
template <typename T, std::size_t N>
inline auto operator+(const T& n, const MatrixRef<T, N>& x) -> Matrix<T, N> {
  Matrix<T, N> res{x};
  res += n;
  return res;
}

template <typename T, std::common_with<T> U>
inline auto operator*(const Matrix<T, 1>& u, const Matrix<U, 1>& v)
    -> Matrix<std::common_type_t<T, U>, 2> {
  const std::size_t kN{u.extent(0)};
  const std::size_t kM{v.extent(0)};
  Matrix<T, 2> res(kN, kM);  // 一个 kN * kM 矩阵
  for (std::size_t i{}; i != kN; ++i) {
    for (std::size_t j{}; j != kM; ++j) {
      res(i, j) = u[i] * v[j];
    }
  }
  return res;
}

template <typename T, std::common_with<T> U>
inline auto operator*(const Matrix<T, 2>& m, const Matrix<U, 1>& v)
    -> Matrix<std::common_type_t<T, U>, 1> {
  assert(m.extent(1) == v.extent(0));

  const std::size_t kN{m.extent(0)};
  Matrix<T, 1> res(kN);
  for (std::size_t i{}; i != kN; ++i) {
    for (std::size_t j{}; j != kN; ++j) {
      res(i) += m(i, j) * v(j);
    }
  }
  return res;
}

template <typename T, std::common_with<T> U>
inline auto dot_product(const MatrixRef<T, 1>& a, const MatrixRef<U, 1>& b)
    -> std::common_type_t<T, U> {
  return std::inner_product(a.begin(), a.end(), b.begin(), 0.0);
}

template <typename T, std::common_with<T> U>
inline auto operator*(const Matrix<T, 2>& m1, const Matrix<U, 2>& m2)
    -> Matrix<T, 2> {
  const std::size_t kN{m1.extent(0)};
  const std::size_t kM{m1.extent(1)};
  assert(kM == m2.extent(0));
  ;  // 列数与行数必须匹配

  const std::size_t kP = m2.extent(1);
  Matrix<T, 2> res(kN, kP);
  for (std::size_t i{}; i != kN; ++i) {
    for (std::size_t j{}; j != kM; ++j) {
      for (std::size_t k{}; k != kP; ++k) {
        res(i, j) = dot_product(m1[i], m2.col(j));
      }
    }
  }
  return res;
}

template <typename T, std::size_t N>
auto Matrix<T, N>::row(std::size_t n) -> MatrixRef<T, N - 1> {
  assert(n < rows());
  MatrixSlice<N - 1> row;
  slice_dim<0>(n, desc_, row);
  return {row, data()};
}
/* template <typename T>
auto Matrix<T, 1>::row(std::size_t i) -> T& {
  return &elems_[i];
}
template <typename T>
auto Matrix<T, 0>::row(std::size_t n) = delete; */

template <typename T, std::size_t N>
auto Matrix<T, N>::col(std::size_t n) -> MatrixRef<T, N - 1> {
  assert(n < cols());
  MatrixSlice<N - 1> col;
  slice_dim<0>(n, desc_, col);
  return {col, data()};
}

template <typename T, std::size_t N>  // 整数下标
auto Matrix<T, N>::operator()(RequestingElement auto... args) -> T& {
  assert(check_bounds(desc_, args...));
  return *(data() + desc_(args...));
}

template <typename T, std::size_t N>  // 切片下标
auto Matrix<T, N>::operator()(const RequestingSlice auto&... args)
    -> MatrixRef<T, N> {
  MatrixSlice<N> d;
  d.start = do_slice(desc_, d, args...);
  return {d, data()};
}

#endif