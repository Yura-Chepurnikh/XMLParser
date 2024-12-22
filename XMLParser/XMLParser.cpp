// XMLParser.cpp: определяет точку входа для приложения.
//

#include "XMLParser.h"
#include "./include/lexer.hpp"
#include "./include/parser.hpp"
#include <fstream>
#include <filesystem>
#include <sstream>
#include <string>
using namespace std;

int parse_file(const string& str) {
	std::ifstream input_file(str);

	if (!input_file) {
		cerr << "\033[31m" << str << " opening error!!!\033[0m" << endl;
		return 1;
	}

	std::ostringstream buffer;
	buffer << input_file.rdbuf();
	std::string content = buffer.str();

	content.erase(std::remove(content.begin(), content.end(), '\n'), content.end());

	Parser parser(content);
	parser.Parse();
	cout << endl;
	return 0;
}

int main()
{
	parse_file(R"(D:\XMLParser\XMLParser\XML Files\first.txt)");
	parse_file(R"(D:\XMLParser\XMLParser\XML Files\second.txt)");
	parse_file(R"(D:\XMLParser\XMLParser\XML Files\third.txt)");
	return 0;
}
