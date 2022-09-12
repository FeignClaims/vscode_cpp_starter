#include "lexer.hpp"

#include "error.hpp"

#include <cctype>
#include <iostream>  // 冗余：在 lexer.h 已经有了

lexer::TokenStream ts;                    // 默认“从 cin 中读”
auto lexer::TokenStream::get() -> Token { /*...*/
}
auto lexer::TokenStream::current() -> Token& { /*...*/
}