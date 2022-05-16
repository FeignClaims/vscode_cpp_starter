#include "dc.hpp"

#include <cctype>
#include <iostream>  // 冗余的：dc.h 已经有了

lexer::TokenStream ts;

auto lexer::TokenStream::get() -> Token { /*...*/
}

auto lexer::TokenStream::current() -> Token& { /*...*/
}