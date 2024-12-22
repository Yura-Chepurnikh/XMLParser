#include "../include/lexer.hpp"
#include <ctype.h>
#include <string>

using namespace std;

Lexer::Lexer(const std::string& text) : m_text(text), m_position(0) { }

SyntaxToken Lexer::NextToken() {
    if (m_position >= m_text.size())
        return SyntaxToken(m_position, "\0", SyntaxKind::EOF_TOKEN);

    if (isalnum(GetCurrentChar())) {
        int start = m_position;

        while (isalnum(GetCurrentChar()))
            Next();

        int len = m_position - start;
        std::string str = m_text.substr(start, len);
        return SyntaxToken(start, str, SyntaxKind::ALNUM);
    }
    else if (isspace(GetCurrentChar())) {
        int start = m_position;

        while (isspace(GetCurrentChar()))
            Next();

        int len = m_position - start;
        std::string str = m_text.substr(start, len);
        return SyntaxToken(start, str, SyntaxKind::WHITE_SPACE);
    }

    char currentChar = GetCurrentChar();
    string content = to_string(currentChar);

    switch (currentChar) {
    case '<':
        return SyntaxToken(m_position++, "<", SyntaxKind::OPEN_TAG);
    case '>':
        return SyntaxToken(m_position++, ">", SyntaxKind::CLOSE_TAG);
    case '/':
        return SyntaxToken(m_position++, "/", SyntaxKind::SLASH);
    case '=':
        return SyntaxToken(m_position++, "=", SyntaxKind::EQUAL_TOKEN);
    case '"':
        return SyntaxToken(m_position++, "\"", SyntaxKind::MARKS_TYPE);
    case '-':
        return SyntaxToken(m_position++, "-", SyntaxKind::DASH);
    case '!':
        return SyntaxToken(m_position++, "!", SyntaxKind::EXCLAMATION_POINT);
    case '?':
        return SyntaxToken(m_position++, "?", SyntaxKind::QUESTION_MARK);
    default:
        return SyntaxToken(m_position++, content, SyntaxKind::SLASH);;
    }
}

char Lexer::GetCurrentChar() {
    if (m_position >= m_text.size())
        return '\0';
    return m_text[m_position];
}

void Lexer::Next() { ++m_position; }

