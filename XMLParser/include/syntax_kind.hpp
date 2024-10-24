#pragma once

#include <iostream>

enum class SyntaxKind {
	OPEN_TAG,
	CLOSE_TAG,
	SLASH,
	ALNUM,
	WHITE_SPACE,
	EOF_TOKEN, 
	UNKNOWN_TYPE,
};

std::ostream& operator<<(std::ostream& stream, SyntaxKind& kind);