#pragma once

#include "../include/syntax_kind.hpp"
#include <string>

struct SyntaxToken {
    int position;
    std::string text;
    SyntaxKind kind;

    SyntaxToken(int position = 0,
        std::string text = nullptr,
        SyntaxKind kind = SyntaxKind::UNKNOWN_TYPE);
};