#include "../include/parser.hpp"
#include <cstddef>
#include <iostream>
#include <string>
using namespace std;

Parser::Parser(const std::string& text) : m_text(text), m_position(0)
{
    Lexer* lexer = new Lexer(text);
    std::vector<SyntaxToken> raw_tokens;

    while (true) {
        auto token = lexer->NextToken();
        if (token.m_kind == SyntaxKind::EOF_TOKEN)
            break;

        if (token.m_kind != SyntaxKind::UNKNOWN_TYPE &&
            token.m_kind != SyntaxKind::EOF_TOKEN && 
            token.m_kind != SyntaxKind::WHITE_SPACE &&
            token.m_kind != SyntaxKind::MARKS_TYPE)
            raw_tokens.push_back(token);
    }

    for (size_t i = 1; i < raw_tokens.size(); i++)
    {
        if (raw_tokens[i - 1].m_kind == SyntaxKind::CLOSE_TAG &&
            raw_tokens[i].m_kind == SyntaxKind::ALNUM) 
        {
            raw_tokens[i].m_kind = SyntaxKind::ALNUM_VALUE;
        }

        else if (raw_tokens[i - 1].m_kind == SyntaxKind::ALNUM &&
            raw_tokens[i].m_kind == SyntaxKind::EQUAL_TOKEN &&
            raw_tokens[i+1].m_kind == SyntaxKind::ALNUM) 
        {
            raw_tokens[i-1].m_kind = SyntaxKind::KEY;
            raw_tokens[i+1].m_kind = SyntaxKind::VALUE;
        }
    }

    for (size_t i = 0; i < raw_tokens.size(); i++)
    {
        if (raw_tokens[i].m_kind == SyntaxKind::ALNUM_VALUE ||
            raw_tokens[i].m_kind == SyntaxKind::ALNUM ||
            raw_tokens[i].m_kind == SyntaxKind::KEY ||
            raw_tokens[i].m_kind == SyntaxKind::VALUE)
            tokens.push_back(raw_tokens[i]);
    }

    for (size_t i = 0; i < tokens.size(); i++)
        cout << tokens[i].m_kind << " " << tokens[i].m_position << " " << tokens[i].m_text << endl;

    delete lexer;
}

void Parser::Next() { ++m_position; }

SyntaxToken Parser::Peek(int offset) {
    int pos = m_position + offset;
    if (pos >= tokens.size())
        return tokens[tokens.size() - 1];
    return tokens[pos];
}

SyntaxToken Parser::GetCurrentToken() {
    return Peek(0);
}

void Parser::Parse() {
    Node* global_root = new Node(tokens[0].m_text);
    Node* current_root = global_root;

    int i = 1;
    while (i > 0) {
        if (tokens[i].m_text != tokens[i - 1].m_text) {
            if (tokens[i].m_kind == SyntaxKind::ALNUM_VALUE) {
                current_root->m_value = tokens[i].m_text; 
                tokens.erase(tokens.begin() + i);
            }
            else if (tokens[i].m_kind == SyntaxKind::KEY) {
                current_root->m_key_value.m_key = tokens[i].m_text;
                current_root->m_key_value.m_value = tokens[i+1].m_text;
                tokens.erase(tokens.begin() + i);
                if (i > 0)
                    tokens.erase(tokens.begin() + i);
            }
            else {
                Node* newNode = new Node(tokens[i].m_text);
                current_root->m_children.push_back(newNode);
                Node* prev_node = current_root;
                current_root = current_root->m_children.back();
                current_root->m_parent = prev_node;
                ++i;
            }
        }
        else {
            std::cout << "\n";
            tokens.erase(tokens.begin() + i);
            if (i > 0)
                tokens.erase(tokens.begin() + i - 1);
            i--;
            current_root = current_root->m_parent;
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
    std::cout << node->m_key << " <" << node->m_value << "> " << "<" << node->m_key_value.m_key << " : " << node->m_key_value.m_value << ">" << std::endl;

    std::string newPrefix = prefix + (isLast ? "    " : "|   ");

    for (size_t i = 0; i < node->m_children.size(); ++i) {
        bool lastChild = (i == node->m_children.size() - 1);
        Display(node->m_children[i], newPrefix, lastChild);
    }

}

