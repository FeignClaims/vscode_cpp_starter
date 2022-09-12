namespace his_string {
class String {};
auto operator+(const String&, const String&) -> String;
auto operator+(const String&, const char*) -> String;
void fill(char);
}  // namespace his_string

namespace her_vector {
template <typename T>
class Vector {};
}  // namespace her_vector

namespace my_lib {
using namespace his_string;
using namespace her_vector;
void my_fct(String&);
}  // namespace my_lib