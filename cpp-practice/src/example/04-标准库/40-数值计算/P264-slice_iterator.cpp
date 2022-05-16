#include <compare>
#include <valarray>

template <typename T>
class SliceIterator {
 public:
  SliceIterator(std::valarray<T>* vv, std::slice ss, std::size_t pos = {})
      : v{vv}, s{ss}, curr{} {}

  auto end() const -> SliceIterator { return {this, s, s.size()}; }

  auto operator++() -> SliceIterator& {
    ++curr;
    return *this;
  }
  auto operator++(int) -> SliceIterator {
    auto t = *this;
    ++curr;
    return t;
  }

  auto operator[](std::size_t i) -> T& {  // C 风格下标
    return ref(i);
  }
  auto operator()(std::size_t i) -> T& {  // Fortran 风格下标
    return ref(i);
  }
  auto operator*() -> T& {  // 当前元素
    return ref(curr);
  }

  auto operator<=>(const SliceIterator& that) const -> std::partial_ordering {
    if (auto cmp = curr <=> that.curr; cmp != 0) {
      return cmp;
    }
    if (auto cmp = s.stride() <=> that.s.stride(); cmp != 0) {
      return cmp;
    }
    return s.start() <=> that.s.start();
  }

 private:
  auto ref(std::size_t i) const -> T& {
    return (*v)[s.start() + i * s.stride()];
  }

  std::valarray<T>* v;
  std::slice s;
  std::size_t curr;  // 当前元素索引
};