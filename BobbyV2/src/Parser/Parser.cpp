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
		Regular expression
		==================
		Procedure			: "^\\s*procedure\\s*(\\w{1,})\\s*\\{\\s*"
		if statement		: ""
		while statement		: ""
		call statement		: ""
		assign statement	: ""
	*/

	
	std::string delimiter = "\n";
	std::regex procedure("^\\s*procedure\\s*(\\w{1,})\\s*\\{\\s*");

	size_t pos = 0;
	std::string token;
	while ((pos = contents.find(delimiter)) != std::string::npos) {
		std::smatch matches;
		token = contents.substr(0, pos);

		//std::cout << "[Parse] Print contents: " + token << std::endl;
		std::regex_match(token, matches, procedure);
		//std::cout << std::regex_match(token, matches, procedure) << std::endl;

		contents.erase(0, pos + delimiter.length());
		
		if (!matches.empty())
			std::cout << "[Parse found procedure] " + std::string(matches[1]) << std::endl;
	}
	//std::cout << "[Parse] Print contents: " << std::endl;
	//std::cout << contents << std::endl;

	/*
	std::string str = " Mem(100)=120";
	std::regex regex("^[\\s]*Mem\\(([0-9]+)\\)\\s*=\\s*([0-9]+(\\.[0-9]+)?)\\s*$");
	std::smatch m;

	std::cout << std::regex_match(str, m, regex) << std::endl;

	for (auto result : m) {
		std::cout << "[Parse] " + std::string(result) << std::endl;
	}
	*/
	/*
	std::string str = "procedure First {";
	std::regex procedure("^\\s*procedure\\s*(\\w{1,})\\s*\\{\\s*");
	std::smatch matches;

	std::cout << std::regex_match(contents, matches, procedure) << std::endl;

	for (auto result : matches) {
		std::cout << "[Parse] " + std::string(result) << std::endl;
	}
	*/
}