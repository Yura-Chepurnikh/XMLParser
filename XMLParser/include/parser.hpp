#pragma once

#include "./lexer.hpp"
#include "./syntax_token.hpp"
#include "./node.hpp"
#include <iostream>
#include <string>
#include <vector>

class Parser {
public:
    Parser(const std::string& text);
    void Display(Node* node, const std::string& prefix, bool isLast);
    void Next();
    SyntaxToken GetCurrentToken();
    SyntaxToken Peek(int offset);
    void DeleteTree(Node* node);
    void Parse();
private:
    std::vector<SyntaxToken> tokens;
    std::vector<SyntaxToken> preOrderTokens;
    int m_position;
    std::string m_text;
};