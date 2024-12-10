#pragma once

#include "./lexer.hpp"
#include "./syntax_token.hpp"
#include "./node.hpp"
#include <iostream>
#include <string>
#include <vector>

class Parser {
public:
    std::vector<SyntaxToken> tokens;
    std::vector<SyntaxToken> preOrderTokens;
    void Display(Node* node, const std::string& prefix, bool isLast);
    Parser(const std::string& text);
    inline void Next();
    SyntaxToken GetCurrentToken();
    SyntaxToken Peek(int offset);
    void Parse();
private:
    int m_position;
    std::string m_text;
};