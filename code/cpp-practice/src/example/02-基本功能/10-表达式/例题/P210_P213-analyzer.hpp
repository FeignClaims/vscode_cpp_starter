#ifndef THECPPPROGRAMMINGLANGUAGE_ANALYZER_HPP
#define THECPPPROGRAMMINGLANGUAGE_ANALYZER_HPP

#include "P213-token_stream.hpp"

#include <map>
#include <string>

auto prim(bool get, std::map<std::string, double>& table, TokenStream& ts)
    -> double;

auto term(bool get, std::map<std::string, double>& table, TokenStream& ts)
    -> double;

auto expr(bool get, std::map<std::string, double>& table, TokenStream& ts)
    -> double;

#endif