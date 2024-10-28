#pragma once

#include "./lexer.hpp"
#include "./syntax_token.hpp"
#include "./node.hpp"
#include <iostream>
#include <string>
#include <vector>

class Parser {
private:
    int position;
    std::string text;

public:
    std::vector<SyntaxToken> tokens;

    // Node* root = new Node(tokens[0].text);
    // Node* globalRoot = root;

    std::vector<SyntaxToken> preOrderTokens;

    void Display(Node* node, const std::string& prefix, bool isLast);

    Node* FindNode(Node* root, Node* findNode);

    Parser(const std::string& text);

    inline void Next();
    SyntaxToken GetCurrentToken();
    SyntaxToken Peek(int offset);
    void Parse();
    void ParseRec(int ptr, const std::string root, std::string indent);
};