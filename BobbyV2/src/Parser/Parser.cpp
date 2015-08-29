#include "Parser.h"
#include <string>

using namespace std;

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

void Parse::concreteSyntaxValidator(string contents) {

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
	string delimiter = "\n"; // split string by newline
	size_t pos = 0;	// initial position
	string token; // individual item after split

	while ((pos = contents.find(delimiter)) != string::npos) {
		
		token = contents.substr(0, pos);
		
		smatch procedure_matches;
		regex procedure("^\\s*procedure\\s*(\\w{1,})\\s*\\{\\s*");

		smatch ifstmt_matches;
		regex ifstmt("^\\s*if\\s+(\\w{1,})\\s+then\\s+\\{\\s*");

		smatch else_matches;
		regex elsestmt("^\\s*else\\s+(\\{)\\s*");

		smatch while_matches;
		regex whilestmt("^\\s*while\\s+(\\w{1,})\\s+\\{\\s*");

		smatch call_matches;
		regex call("^\\s*call\\s+(\\w{1,})\\s*\\;\\s*");

		smatch assign_matches;
		regex assign("^\\s*(\\w{1,})\\s*=\\s*([^=]*)\\;\\s*");

		smatch end_matches;
		regex end("^\\s*(\\})\\s*");

		
		/*
		for (auto result : procedure_matches) {
			cout << "[Parse found procedure] " + string(result) << endl;
		}
		*/

		/*
			Regex matching for all entities and relationships
		*/
		regex_match(token, procedure_matches, procedure);
		regex_match(token, ifstmt_matches, ifstmt);
		regex_match(token, else_matches, elsestmt);
		regex_match(token, while_matches, whilestmt);
		regex_match(token, call_matches, call);
		regex_match(token, assign_matches, assign);
		regex_match(token, end_matches, end);
		
		/*
			Printing match results
		*/
		if (!procedure_matches.empty()) {
			cout << "[Parse found procedure] " + string(procedure_matches[0]) << endl;
		}
		if (!ifstmt_matches.empty()) {
			cout << "[Parse found if] " + string(ifstmt_matches[0]) << endl;
		}
		if (!else_matches.empty()) {
			cout << "[Parse found else] " + string(else_matches[0]) << endl;
		}
		if (!while_matches.empty()) {
			cout << "[Parse found while] " + string(while_matches[0]) << endl;
		}
		if (!call_matches.empty()) {
			cout << "[Parse found call] " + string(call_matches[0]) << endl;
		}
		if (!assign_matches.empty()) {
			cout << "[Parse found assign] " + string(assign_matches[0]) << endl;
		}
		if (!end_matches.empty()) {
			cout << "[Parse found end] " + string(end_matches[0]) << endl;
		}

		contents.erase(0, pos + delimiter.length());	
	}
}