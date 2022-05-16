#include "error.hpp"
#include "lexer.hpp"
#include "parser.hpp"

using error::error;
using namespace lexer;

namespace parser {  // 实现者接口
auto prim(bool get) -> double;
auto term(bool get) -> double;
auto expr(bool get) -> double;
}  // namespace parser