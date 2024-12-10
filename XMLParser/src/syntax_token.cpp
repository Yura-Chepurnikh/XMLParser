#include "../include/syntax_token.hpp"

SyntaxToken::SyntaxToken(int position, std::string text, SyntaxKind kind) :
	m_position(position), m_text(text), m_kind(kind) { }
