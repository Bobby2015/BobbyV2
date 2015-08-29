#include "Parser.h"

// Constructor
Parse::Parse() 
{
	first = 3;
	second = 4;
}
// Destructor
Parse::~Parse() 
{
	//De-allocation of memory if needed
}

// function
int Parse::add(unsigned x, unsigned y)
{
	return x + y;
}

void Parse::concreteSyntaxValidator(std::string contents) {
	/*
	std::string str2("procedure");
	std::size_t found = contents.find(str2);

	if (found != std::string::npos)
	std::cout << "first 'procedure' found at: " << found << '\n';
	found = contents.find("procedure", found + 1, 6);
	if (found != std::string::npos)
	std::cout << "second 'procedure' found at: " << found << '\n';
	*/

	std::string delimiter = "\n";

	size_t pos = 0;
	std::string token;
	while ((pos = contents.find(delimiter)) != std::string::npos) {
		token = contents.substr(0, pos);
		std::cout << "[Parse] Print contents: " + token << std::endl;
		contents.erase(0, pos + delimiter.length());
	}
	std::cout << "[Parse] Print contents: " << std::endl;
	std::cout << contents << std::endl;
}