#pragma once

#include "./syntax_token.hpp"
#include <iostream>
#include <string>

class Lexer {
private:
    int position;
    std::string text;
public:
    Lexer(const std::string& text);
    char GetCurrentChar();
    inline void Next();
    SyntaxToken NextToken();
};