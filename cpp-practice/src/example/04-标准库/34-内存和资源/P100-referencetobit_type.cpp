#include <cstddef>
template <std::size_t N>
class Bitset {
 public:
  class Reference {  // 引用单一二进制位
   private:
    friend class Bitset;
    Reference() noexcept;

   public:  // 支持 [0:b.size()) 间从 0 开始的下标操作
    ~Reference() noexcept;

    auto operator=(bool x) noexcept -> Reference&;  // 用于 b[i] = x 赋值
    auto operator=(const Reference&) noexcept
        -> Reference&;  // 用于 b[i] = b[j] 赋值

    auto operator~() const noexcept -> bool;  // 返回 ~b[i]
    operator bool() const noexcept;           // 用于 x = b[i] 转换
    auto flip() noexcept -> Reference&;       // b[i].flip()
  };
};