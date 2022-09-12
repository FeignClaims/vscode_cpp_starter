#include <type_traits>
#include <utility>

template <typename Contained>
struct Optional1 {
  constexpr auto operator=(Contained&& data) -> Optional1& {
    this->data = std::move(data);
    initialized = true;
    return *this;
  }

  // star: 通过类型萃取/约束与概念，对一个容器类型的析构函数进行优化
  constexpr ~Optional1() = default;
  constexpr ~Optional1() requires(
      !std::is_trivially_destructible_v<Contained>) {
    if (initialized) {
      data_.~Contained();
    }
  }

  union {
    Contained data_;
  };
  bool initialized{true};
};

template <typename Type>
struct OptionalBase {
  constexpr ~OptionalBase() { static_cast<Type*>(this)->data.~Contained(); }
};

template <typename Type>
  requires std::is_trivially_destructible_v<Type>
struct OptionalBase<Type> {
  constexpr ~OptionalBase() = default;
};

template <typename Contained>
struct Optional2 : OptionalBase<Contained> {
  constexpr auto operator=(Contained&& data) -> Optional2& {
    this->data = std::move(data);
    initialized = true;
    return *this;
  }

  union {
    Contained data;
  };
  bool initialized{true};
};
