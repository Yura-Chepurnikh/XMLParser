#pragma once

#include "../include/syntax_kind.hpp"
#include <string>

struct SyntaxToken {
    int m_position;
    std::string m_text;
    SyntaxKind m_kind;

    SyntaxToken(int position = 0,
        std::string text = nullptr,
        SyntaxKind kind = SyntaxKind::UNKNOWN_TYPE);
};