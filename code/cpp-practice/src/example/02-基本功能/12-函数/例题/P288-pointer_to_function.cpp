#include <string>
void error(std::string) {
}
void (*f1)(std::string) = &error;  // note: 等价于 = error
void (*f2)(std::string) = error;   // note: 等价于 = &error

void g() {
  f1("Vasa");          // note: 等价于 (*f1)("Vasa")
  (*f1)("Mary Rose");  // note: 等价于 f1("Mary Rose")
}