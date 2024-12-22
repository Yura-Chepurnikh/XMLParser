// XMLParser.cpp: определяет точку входа для приложения.
//

#include "XMLParser.h"
#include "./include/lexer.hpp"
#include "./include/parser.hpp"
#include <fstream>
#include <string>
using namespace std;

int main()
{
	std::ifstream input_file();
	string input = R"(<cinema><movie1 hole="hole1" a="a"><name>name1</name><price>10$</price><date>August</date></movie1><movie2 hole="hole2"><name>name2</name><price>15$</price><date>August</date></movie2><movie3 hole="hole3"><name>name3</name><price>20$</price><date>August</date></movie3></cinema>)";
	Parser parser(input);
	parser.Parse();
}
