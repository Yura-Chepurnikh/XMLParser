#include "../include/syntax_kind.hpp"
using namespace std;

std::ostream& operator<<(std::ostream& stream, SyntaxKind& kind) {
    switch (kind) {
    case SyntaxKind::ALNUM:
        stream << "ALNUM";
        break;
    case SyntaxKind::ALNUM_VALUE:
        stream << "ALNUM_VALUE";
        break;
    case SyntaxKind::OPEN_TAG:
        stream << "OPEN_TAG";
        break;
    case SyntaxKind::CLOSE_TAG:
        stream << "CLOSE_TAG";
        break;
    case SyntaxKind::EQUAL_TOKEN:
        stream << "EQUAL_TOKEN";
        break;
    case SyntaxKind::KEY:
        stream << "KEY";
        break;
    case SyntaxKind::VALUE:
        stream << "VALUE";
        break;
    default:
        stream << "UNKNOWN_TYPE";
        break;
    }
    return stream;
}