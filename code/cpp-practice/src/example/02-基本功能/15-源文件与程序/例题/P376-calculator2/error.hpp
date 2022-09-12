#include <string>

namespace error {
extern int number_of_errors;
auto error(const std::string&) -> double;
}  // namespace error