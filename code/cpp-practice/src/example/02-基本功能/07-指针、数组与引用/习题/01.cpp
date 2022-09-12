auto main() -> int {
  char* a{};       // a pointer to a character
  int b[10]{};     // an array of 10 integers
  int(&c)[10]{b};  // a reference to an array of 10 integers
  char(*d)[10]{};  // a pointer to an array of character strings
  char** e{};      // a pointer to a pointer to a character
  const int f{};   // a constant integer
  const int* g{};  // a pointer to a constant integer
  int* const h{};  // a constant pointer to an integer
}