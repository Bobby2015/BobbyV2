#include "Parser.h"

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

void Parse::addNewLine(string from, string to, string *content)
{
	size_t start_pos = 0;
	while ((start_pos = content->find(from, start_pos)) != std::string::npos) {
		content->replace(start_pos, from.length(), to);
		start_pos += to.length(); // Handles case where 'to' is a substring of 'from'
	}
}

bool Parse::concreteSyntaxValidator(string contents) {

	/*
		Algorithm
		========================
		1. Remove all newline.
		2. For all "{", "}", ";", add a newline after it.
		3. Use regex to extract entities and relationships
	*/

	string *contentPointer = &contents;


	// Remove new line
	string::size_type pos1 = 0; // Must initialize
	while ((pos1 = contents.find("\r\n", pos1)) != string::npos) {
		contents.erase(pos1, 2);
	}

	// Add newline to {
	addNewLine("{", "{\n", contentPointer);

	
	// Add newline to }
	string from1("}");
	string to1("}\n");
	size_t start_pos1 = 0;
	while ((start_pos1 = contents.find(from1, start_pos1)) != std::string::npos) {
		contents.replace(start_pos1, from1.length(), to1);
		start_pos1 += to1.length(); // Handles case where 'to' is a substring of 'from'
	}

	// Add newline to ;
	string from2(";");
	string to2(";\n");
	size_t start_pos2 = 0;
	while ((start_pos2 = contents.find(from2, start_pos2)) != std::string::npos) {
		contents.replace(start_pos2, from2.length(), to2);
		start_pos2 += to2.length(); // Handles case where 'to' is a substring of 'from'
	}

	// Implement regex
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

	string delimiter = "\n"; // split string by newline
	size_t pos = 0;	// initial position
	string token; // individual item after split

	
	regex procedure("^\\s*procedure\\s*(\\w{1,})\\s*\\{\\s*");
	regex ifstmt("^\\s*if\\s+(\\w{1,})\\s+then\\s+\\{\\s*");
	regex elsestmt("^\\s*else\\s+(\\{)\\s*");
	regex whilestmt("^\\s*while\\s+(\\w{1,})\\s+\\{\\s*");
	regex call("^\\s*call\\s+(\\w{1,})\\s*\\;\\s*");
	regex assign("^\\s*(\\w{1,})\\s*=\\s*([^=]*)\\;\\s*");
	regex end("^\\s*(\\})\\s*");



	while ((pos = contents.find(delimiter)) != string::npos) {

		token = contents.substr(0, pos);

		smatch procedure_matches;
		smatch ifstmt_matches;
		smatch else_matches;
		smatch while_matches;
		smatch call_matches;
		smatch assign_matches;
		smatch end_matches;

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
		} else if (!ifstmt_matches.empty()) {
			cout << "[Parse found if] " + string(ifstmt_matches[0]) << endl;
		} else if (!else_matches.empty()) {
			cout << "[Parse found else] " + string(else_matches[0]) << endl;
		} else if (!while_matches.empty()) {
			cout << "[Parse found while] " + string(while_matches[0]) << endl;
		} else if (!call_matches.empty()) {
			cout << "[Parse found call] " + string(call_matches[0]) << endl;
		} else if (!assign_matches.empty()) {
			cout << "[Parse found assign] " + string(assign_matches[0]) << endl;
		} else if (!end_matches.empty()) {
			cout << "[Parse found end] " + string(end_matches[0]) << endl;
		}

		contents.erase(0, pos + delimiter.length());
	}

	return true;
} 

