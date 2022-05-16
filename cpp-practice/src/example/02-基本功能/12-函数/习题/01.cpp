void a(char*, int&);
using func = void(char*, int&);
func* b{};
auto c(func*) -> func*;