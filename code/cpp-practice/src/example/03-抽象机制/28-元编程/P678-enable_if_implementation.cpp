template <bool B, typename T = void>
class enable_if {
 public:
  using type = T;
};

template <typename T>
class enable_if<false, T> {};  // 若 B == false 则没有 ::type

template <bool B, typename T = void>
using EnableIf = typename enable_if<B, T>::type;