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
            token.kind != SyntaxKind::EOF_TOKEN && 
            token.kind != SyntaxKind::WHITE_SPACE &&
            token.kind != SyntaxKind::MARKS_TYPE)
            tokensasdasdasdas.push_back(token);
    }

    for (size_t i = 1; i < tokensasdasdasdas.size(); i++)
    {
        if (tokensasdasdasdas[i - 1].kind == SyntaxKind::CLOSE_TAG &&
            tokensasdasdasdas[i].kind == SyntaxKind::ALNUM) {
            
            cout << "asd" << endl;
            tokensasdasdasdas[i].kind = SyntaxKind::ALNUM_VALUE;
        }

        else if (tokensasdasdasdas[i - 1].kind == SyntaxKind::ALNUM &&
            tokensasdasdasdas[i].kind == SyntaxKind::EQUAL_TOKEN &&
            tokensasdasdasdas[i+1].kind == SyntaxKind::ALNUM) {

            tokensasdasdasdas[i-1].kind = SyntaxKind::JSON_KEY;
            tokensasdasdasdas[i+1].kind = SyntaxKind::JSON_VALUE;
        }
    }


    for (size_t i = 0; i < tokensasdasdasdas.size(); i++)
    {
        if (tokensasdasdasdas[i].kind == SyntaxKind::ALNUM_VALUE ||
            tokensasdasdasdas[i].kind == SyntaxKind::ALNUM ||
            tokensasdasdasdas[i].kind == SyntaxKind::JSON_KEY ||
            tokensasdasdasdas[i].kind == SyntaxKind::JSON_VALUE)
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
                current_root->value = tokens[i].text; 
                tokens.erase(tokens.begin() + i);
            }
            else if (tokens[i].kind == SyntaxKind::JSON_KEY) {
                current_root->json_kv.json_key = tokens[i].text;
                current_root->json_kv.json_value = tokens[i+1].text;
                tokens.erase(tokens.begin() + i);
                if (i > 0)
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

    std::cout << node->key << " (" << node->value << ") " << "(" << node->json_kv.json_key << " : " << node->json_kv.json_value << ")" << std::endl;

    std::string newPrefix = prefix + (isLast ? "    " : "|   ");

    for (size_t i = 0; i < node->children.size(); ++i) {
        bool lastChild = (i == node->children.size() - 1);
        Display(node->children[i], newPrefix, lastChild);
    }

}

//<cinema><movie1 hole1="Red"><name>some_name1</name><price>10$</price><date>some_date1</date></movie1><movie2 hole2="Blue"><name>some_name2</name><price>20$</price><date>some_date2</date></movie2><movie3 hole3="Blue"><name>some_name3</name><price>30$</price><date>some_date3</date></movie3></cinema>

//<cinema><movie1 hole="Red"><name>name1</name><price>10$</price><date>August</date></movie1><movie2 hole="Blue"><name>name2</name><price>15$</price><date>August</date></movie2><movie3 hole="Blue"><name>name3</name><price>20$</price><date>August</date></movie3></cinema>