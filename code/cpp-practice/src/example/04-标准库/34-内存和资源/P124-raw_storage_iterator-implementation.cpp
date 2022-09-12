#include <iterator>

template <typename T, std::output_iterator<T> Out>
class RawStorageIterator {
 public:
  using iterator_type = void;
  using iterator_concept = std::output_iterator_tag;
  using iterator_category = std::output_iterator_tag;
  using value_type = void;
  using difference_type = void;
  using pointer = void;
  using reference = void;

  explicit RawStorageIterator(Out pp) : p{pp} {}

  auto operator=(const T& val) -> RawStorageIterator& {
    new (&*p) T{val};  // 将 val 置于 *p 中
    return *this;
  }

  auto operator*() -> RawStorageIterator& { return *this; }

  auto operator++() -> RawStorageIterator& {  // 前置递增
    ++p;
    return *this;
  }
  auto operator++(int) -> RawStorageIterator {  // 后置递增
    auto t = *this;
    ++p;
    return t;
  }

 private:
  Out p;
};