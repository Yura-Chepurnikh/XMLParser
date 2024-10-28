#pragma once

#include <iostream>

enum class SyntaxKind {
	OPEN_TAG,
	CLOSE_TAG,
	SLASH,
	ALNUM,
	ALNUM_VALUE,
	WHITE_SPACE,
	EOF_TOKEN,
	EQUAL_TOKEN,
	JSON_KEY,
	JSON_VALUE,
	MARKS_TYPE,
	UNKNOWN_TYPE,
};

std::ostream& operator<<(std::ostream& stream, SyntaxKind& kind);