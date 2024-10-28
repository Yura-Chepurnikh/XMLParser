#include "../include/parser.hpp"
#include <cstddef>
#include <iostream>
#include <string>
using namespace std;

Parser::Parser(const std::string& text) : text(text), position(0)
{
    Lexer* lexer = new Lexer(text);
    std::vector<SyntaxToken> tokensasdasdasdas;

    while (true) {
        auto token = lexer->NextToken();

        if (token.kind == SyntaxKind::EOF_TOKEN)
            break;

        //cout << token.kind << " " << token.position << " " << token.text << endl;

        if (token.kind != SyntaxKind::UNKNOWN_TYPE &&
            token.kind != SyntaxKind::EOF_TOKEN)
            tokensasdasdasdas.push_back(token);
    }

    for (size_t i = 1; i < tokensasdasdasdas.size(); i++)
    {
        if (tokensasdasdasdas[i - 1].kind == SyntaxKind::CLOSE_TAG &&
            tokensasdasdasdas[i].kind == SyntaxKind::ALNUM) {
            
            cout << "asd" << endl;
            tokensasdasdasdas[i].kind = SyntaxKind::ALNUM_VALUE;
        }

    }


    for (size_t i = 0; i < tokensasdasdasdas.size(); i++)
    {
        if (tokensasdasdasdas[i].kind == SyntaxKind::ALNUM_VALUE ||
            tokensasdasdasdas[i].kind == SyntaxKind::ALNUM)
            tokens.push_back(tokensasdasdasdas[i]);
    }

    for (size_t i = 0; i < tokens.size(); i++)
    {
        //tokens.push_back(tokensasdasdasdas[i]);
        cout << tokens[i].kind << " " << tokens[i].position << " " << tokens[i].text << endl;
    }

    delete lexer;
}

void Parser::Next() { ++position; }

SyntaxToken Parser::Peek(int offset) {
    int pos = position + offset;
    if (pos >= tokens.size())
        return tokens[tokens.size() - 1];
    return tokens[pos];
}

SyntaxToken Parser::GetCurrentToken() {
    return Peek(0);
}

void Parser::Parse() {
    Node* global_root = new Node(tokens[0].text);
    Node* current_root = global_root;

    int i = 1;
    while (i > 0) {
        if (tokens[i].text != tokens[i - 1].text) {
            if (tokens[i].kind == SyntaxKind::ALNUM_VALUE) {
                std::cout << "surprise motherfucker!!! ";

                current_root->value = tokens[i].text; 
                tokens.erase(tokens.begin() + i);
            }
            else {
                std::cout << "yes ";
                Node* newNode = new Node(tokens[i].text);
                current_root->children.push_back(newNode);
                Node* prev_node = current_root;
                current_root = current_root->children.back();
                current_root->parent = prev_node;
                ++i;
            }
        }
        else {
            std::cout << "\n";
            //std::cout << "i = " <<  i;

            tokens.erase(tokens.begin() + i);
            if (i > 0)
                tokens.erase(tokens.begin() + i - 1);
            i--;
            //std::cout << "i = " << i;

            current_root = current_root->parent;
        }
    }

    Display(global_root, "", true);
}


void Parser::Display(Node* node, const std::string& prefix = "", bool isLast = true) {
    if (!node) return;

    std::cout << prefix;

    if (isLast) {
        std::cout << "+--";
    }
    else {
        std::cout << "|--";
    }

    std::cout << node->key  << node->value << std::endl;

    std::string newPrefix = prefix + (isLast ? "    " : "|   ");

    for (size_t i = 0; i < node->children.size(); ++i) {
        bool lastChild = (i == node->children.size() - 1);
        Display(node->children[i], newPrefix, lastChild);
    }

}
// <roots><root1><child1><child2><child3></child3><child4></child4><child5></child5></child2></child1></root1><root1><child1><child2><child3></child3><child4></child4><child5></child5></child2></child1></root1></roots>

// <roots><root><child1><child2><child3></child3><child4></child4><child5></child5></child2></child1></root><A><B><C></C></B></A></roots>
// <roots><root><child1></child1></root><A><B><C></C></B></A></roots>