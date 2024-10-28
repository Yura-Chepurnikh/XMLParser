// XMLParser.cpp: определяет точку входа для приложения.
//

#include "XMLParser.h"
#include "./include/lexer.hpp"
#include "./include/parser.hpp"

using namespace std;

int main()
{
	while (true) {
		string input;
		cout << ">> ";
		getline(cin, input);

		Parser parser(input);
		parser.Parse();
		/*Lexer lexer(input);

		while (true) {
			SyntaxToken token = lexer.NextToken();

			if (token.kind == SyntaxKind::EOF_TOKEN)
				break;

			cout << token.position << " " << token.kind << " " << token.text << endl;
		}*/
	}
}
