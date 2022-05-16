namespace popular {
inline namespace v3_2 {  // v3_2 提供了 popular 的默认含义
double f(double);
int f(int);
template <typename T>
class c {};
}  // namespace v3_2

namespace v3_0 {
// ...
}  // namespace v3_0

namespace v2_4_2 {
double f(double);
template <typename T>
class c {};
}  // namespace v2_4_2
}  // namespace popular