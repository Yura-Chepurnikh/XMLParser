#pragma once

#include "./syntax_token.hpp"
#include <iostream>
#include <string>

class Lexer {
public:
    Lexer(const std::string& text);
    char GetCurrentChar();
    inline void Next();
    SyntaxToken NextToken();
private:
    int m_position;
    std::string m_text;
};