#include <type_traits>

template <typename T>
using AddReference = std::add_lvalue_reference_t<T>;

template <typename T>
using AddConstReference = std::add_lvalue_reference_t<std::add_const_t<T>>;

/**
 * 基本上，一个 tuple 保存其头（第一个 (type, value) 对）
 * 并从其尾导出其他元素（剩下的 (type, value) 对）
 * 注意，类型是编码在类型中的，并非存为数据
 */
template <typename Head, typename... Tail>
class tuple : private tuple<Tail...> {  // 递归
 private:
  using inherited = tuple<Tail...>;

 public:
  constexpr tuple() = default;  // 默认：空 tuple

  // 用独立的实参构造 tuple：
  explicit tuple(AddConstReference<Head> v, AddConstReference<Tail>... vtail)
      : m_head(v), inherited(vtail...) {}

  // 用另一个 tuple 构造 tuple：
  template <typename... VValues>
  explicit tuple(const tuple<VValues...>& other)
      : m_head(other.head()), inherited(other.tail()) {}

  template <typename... VValues>
  auto operator=(const tuple<VValues...>& other) -> tuple& {  // 赋值
    m_head = other.head();
    tail() = other.tail();
    return *this;
  }
  // ...

 protected:
  Head m_head;

 private:
  auto head() -> AddReference<Head> { return m_head; }
  auto head() const -> AddReference<const Head> { return m_head; }

  auto tail() -> inherited& { return *this; }
  auto tail() const -> const inherited& { return *this; }
};

template <typename... Types>
auto make_tuple(Types&&... t) -> tuple<Types...> {  // 简化版本
  return tuple<Types...>(t...);
}