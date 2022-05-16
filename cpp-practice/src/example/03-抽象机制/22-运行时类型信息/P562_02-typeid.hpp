#include <cstddef>

// STAR: type_info 的定义
class type_info {
  // 数据
 public:
  type_info(const type_info&) = delete;  // 阻止拷贝

  auto operator=(const type_info&) -> type_info& = delete;  // 阻止拷贝

  virtual ~type_info();  // 多态

  auto operator==(const type_info&) const noexcept -> bool;  // 可以比较
  auto operator!=(const type_info&) const noexcept -> bool;

  [[nodiscard]] auto before(const type_info&) const noexcept
      -> bool;  //\* 定义了序，允许 type_id 作为有序容器的关键字
  [[nodiscard]] auto hash_code() const noexcept
      -> std::size_t;  //\* 供 unordered_map 或类似特性使用
  [[nodiscard]] auto name() const noexcept -> const char*;  // 类型名
};