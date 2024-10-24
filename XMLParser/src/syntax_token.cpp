#include "../include/syntax_token.hpp"

SyntaxToken::SyntaxToken(int position, std::string text, SyntaxKind kind) :
	position(position), text(text), kind(kind) { }
