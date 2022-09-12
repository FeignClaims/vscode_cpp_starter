namespace his_lib {
class String {};
template <typename T>
class Vector {};
}  // namespace his_lib

namespace her_lib {
template <typename T>
class Vector {};
class String {};
}  // namespace her_lib

namespace my_lib {
using namespace his_lib;  // his_lib 中的所有实体
using namespace her_lib;  // her_lib 中的所有实体

using her_lib::Vector;  // 解决潜在冲突：使用 her_lib 中的版本
using his_lib::String;  // 解决潜在冲突：使用 his_lib 中的版本

using her_string = her_lib::String;  // 重命名
template <typename T>
using his_vec = his_lib::Vector<T>;  // 重命名

template <typename T>
class List {};  // 其他内容，默认解析为 my_lib::List；
                // 不管 his_lib 或 her_lib 是否提供了 List
}  // namespace my_lib