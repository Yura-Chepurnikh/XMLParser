#include "../include/lexer.hpp"
#include <ctype.h>
#include <string>

using namespace std;

Lexer::Lexer(const std::string& text) : text(text), position(0) { }

SyntaxToken Lexer::NextToken() {
    if (position >= text.size())
        return SyntaxToken(position, "\0", SyntaxKind::EOF_TOKEN);

    if (isalnum(GetCurrentChar())) {
        int start = position;

        while (isalnum(GetCurrentChar()))
            Next();

        int len = position - start;
        std::string str = text.substr(start, len);
        return SyntaxToken(start, str, SyntaxKind::ALNUM);
    }
    else if (isspace(GetCurrentChar())) {
        int start = position;

        while (isspace(GetCurrentChar()))
            Next();

        int len = position - start;
        std::string str = text.substr(start, len);
        return SyntaxToken(start, str, SyntaxKind::WHITE_SPACE);
    }

    char currentChar = GetCurrentChar();
    string content = to_string(currentChar);

    switch (currentChar) {
    case '<':
        return SyntaxToken(position++, "<", SyntaxKind::OPEN_TAG);
    case '>':
        return SyntaxToken(position++, ">", SyntaxKind::CLOSE_TAG);
    case '/':
        return SyntaxToken(position++, "/", SyntaxKind::SLASH);
    default:
        return SyntaxToken(position++, content, SyntaxKind::SLASH);;
    }
}

char Lexer::GetCurrentChar() {
    if (position >= text.size())
        return '\0';
    return text[position];
}

void Lexer::Next() { ++position; }

