# CMakeList.txt: проект CMake для XMLParser; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#

# Добавьте источник в исполняемый файл этого проекта.
add_executable (XMLParser 
	"XMLParser.cpp" 
	"XMLParser.h"

	"include/lexer.hpp"
	"src/lexer.cpp"

	"include/parser.hpp"
	"src/parser.cpp"

	"include/syntax_kind.hpp"
	"src/syntax_kind.cpp"

	"include/syntax_token.hpp"
	"src/syntax_token.cpp"

	"include/node.hpp"
	
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET XMLParser PROPERTY CXX_STANDARD 20)
endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
