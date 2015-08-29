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
		if statement		: "^\\s*if\\s+(\\w{1,})\\s+then\\s+\\{\\s*"
		else statement		: "^\\s*else\\s+(\\{)\\s*"
		while statement		: "^\\s*while\\s+(\\w{1,})\\s+\\{\\s*"
		call statement		: "^\\s*call\\s+(\\w{1,})\\s*\\;\\s*"
		assign statement	: "^\\s*(\\w{1,})\\s*=\\s*([^=]*)\\;\\s*"
		end statement		: "^\\s*(\\})\\s*"
	*/

	contents = contents + "\n"; // add newline at EOF to prevent omitting last line 
	std::string delimiter = "\n"; // split string by newline
	size_t pos = 0;	// initial position
	std::string token; // individual item after split

	while ((pos = contents.find(delimiter)) != std::string::npos) {
		
		token = contents.substr(0, pos);
		
		std::smatch procedure_matches;
		std::regex procedure("^\\s*procedure\\s*(\\w{1,})\\s*\\{\\s*");

		std::smatch ifstmt_matches;
		std::regex ifstmt("^\\s*if\\s+(\\w{1,})\\s+then\\s+\\{\\s*");

		std::smatch else_matches;
		std::regex elsestmt("^\\s*else\\s+(\\{)\\s*");

		std::smatch while_matches;
		std::regex whilestmt("^\\s*while\\s+(\\w{1,})\\s+\\{\\s*");

		std::smatch call_matches;
		std::regex call("^\\s*call\\s+(\\w{1,})\\s*\\;\\s*");

		std::smatch assign_matches;
		std::regex assign("^\\s*(\\w{1,})\\s*=\\s*([^=]*)\\;\\s*");

		std::smatch end_matches;
		std::regex end("^\\s*(\\})\\s*");

		
		/*
		for (auto result : procedure_matches) {
			std::cout << "[Parse found procedure] " + std::string(result) << std::endl;
		}
		*/

		/*
			Regex matching for all entities and relationships
		*/
		std::regex_match(token, procedure_matches, procedure);
		std::regex_match(token, ifstmt_matches, ifstmt);
		std::regex_match(token, else_matches, elsestmt);
		std::regex_match(token, while_matches, whilestmt);
		std::regex_match(token, call_matches, call);
		std::regex_match(token, assign_matches, assign);
		std::regex_match(token, end_matches, end);
		
		/*
			Printing match results
		*/
		if (!procedure_matches.empty()) {
			std::cout << "[Parse found procedure] " + std::string(procedure_matches[0]) << std::endl;
		}
		if (!ifstmt_matches.empty()) {
			std::cout << "[Parse found if] " + std::string(ifstmt_matches[0]) << std::endl;
		}
		if (!else_matches.empty()) {
			std::cout << "[Parse found else] " + std::string(else_matches[0]) << std::endl;
		}
		if (!while_matches.empty()) {
			std::cout << "[Parse found while] " + std::string(while_matches[0]) << std::endl;
		}
		if (!call_matches.empty()) {
			std::cout << "[Parse found call] " + std::string(call_matches[0]) << std::endl;
		}
		if (!assign_matches.empty()) {
			std::cout << "[Parse found assign] " + std::string(assign_matches[0]) << std::endl;
		}
		if (!end_matches.empty()) {
			std::cout << "[Parse found end] " + std::string(end_matches[0]) << std::endl;
		}

		contents.erase(0, pos + delimiter.length());	
	}
}