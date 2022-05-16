#include <iterator>
#include <type_traits>

template <typename Iter>
class ReverseIterator {
 public:
  using iterator_type = Iter;
  using iterator_concept =
      std::conditional_t<std::__is_cpp17_random_access_iterator<Iter>::value,
                         std::random_access_iterator_tag,
                         std::bidirectional_iterator_tag>;
  using iterator_category = std::conditional_t<
      std::__is_cpp17_random_access_iterator<Iter>::value,
      std::random_access_iterator_tag,
      typename std::iterator_traits<Iter>::iterator_category>;
  using value_type = std::iter_value_t<Iter>;
  using difference_type = std::iter_difference_t<Iter>;
  using pointer = typename std::iterator_traits<Iter>::pointer;
  using reference = std::iter_reference_t<Iter>;

  ReverseIterator() = default;
  explicit ReverseIterator(Iter p) : current_{p} {}
  template <typename Iter2>
  ReverseIterator(const ReverseIterator<Iter2>& p) : current_(p.base()) {}

  auto base() const -> Iter { return current_; }  // 当前迭代器值

  auto operator*() const -> reference {
    temp_ = current_;
    return *--temp_;
  }
  auto operator->() const -> pointer;
  auto operator[](difference_type n) const -> reference;

  auto operator++() -> ReverseIterator& {
    --current_;  //\; 不是 ++
    return *this;
  }
  auto operator++(int) -> ReverseIterator {
    ReverseIterator t = current_;
    --current_;
    return t;
  }
  auto operator--() -> ReverseIterator& {
    ++current_;  //\; 不是 --
    return *this;
  }
  auto operator--(int) -> ReverseIterator {
    ReverseIterator t = current_;
    ++current_;
    return t;
  }

  auto operator+(difference_type n) const -> ReverseIterator;
  auto operator+=(difference_type n) -> ReverseIterator&;
  auto operator-(difference_type n) const -> ReverseIterator;
  auto operator-=(difference_type n) -> ReverseIterator&;
  // ...

 protected:
  Iter current_{};  // current 指向 *this 之后的元素

 private:
  Iter temp_;  // 用于生命周期需要超出函数作用域的临时变量
};