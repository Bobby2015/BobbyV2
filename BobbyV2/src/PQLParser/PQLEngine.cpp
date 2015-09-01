#include "PQLEngine.h"

#include <string>
#include <sstream>
#include <iostream>
#include <regex>

using namespace std;

//Constructor
PqlEngine::PqlEngine()
{
	pqlKeyword = PqlKeyword();
}

//Destructor
PqlEngine::~PqlEngine()
{

}

bool PqlEngine::executeQuery(string query) 
{

	bool isSuccess = false;

	isSuccess = validateQuery(query);
	
	if (isSuccess == true)
	{
		evaluateQuery(query);
	}

	return isSuccess;
}

bool PqlEngine::validateQuery(string query)
{
	PQLValidator pqlValidator;

	bool isSuccess = pqlValidator.validateQuery(query);

	return isSuccess;
}

bool PqlEngine::evaluateQuery(string query)
{
	bool isSuccess = false;

	string cleanedQuery = fixWhitespace(query);
	vector <string> separatedQuery = separateQuery(cleanedQuery);

	//	cout << "fixed: " << cleanedQuery << endl;

	for (int i = 0; i < separatedQuery.size(); i++)
	{
		// cout << separatedQuery[i] << endl;

		string currQuery = separatedQuery[i];

		bool isSuccess = identifySingleQuery(currQuery);
	}


	/*istringstream stream(query);
	PqlKeyword pqlKeyword;
	string currWord;

	while (stream >> currWord)
	{
		bool isKeyword = pqlKeyword.isKeywordExist(currWord);

		if (isKeyword)
		{
			if (currWord.compare(PqlKeyword::KEYWORD_SELECT) == 0) {
				cout << "it is a select statement" << endl;
			}
			else {

			}
			cout << currWord << endl;
		}
		
	}*/

	return isSuccess;
}

bool PqlEngine::identifySingleQuery(string query)
{
	bool isSuccess = false;
	string currWord;
	istringstream stream(query);

	stream >> currWord;
	bool isKeyword = pqlKeyword.isKeywordExist(currWord);

	if (isKeyword)
	{
		if (currWord.compare(PqlKeyword::KEYWORD_SELECT) == 0) {
			//execute select
		}
		else if (currWord.compare(PqlKeyword::KEYWORD_STMT) == 0) {
			//execute stmt
		}
		else if (currWord.compare(PqlKeyword::KEYWORD_ASSIGN) == 0) {
			//execute assign
		}
		else if (currWord.compare(PqlKeyword::KEYWORD_WHILE) == 0) {
			//execute while
		}
		else if (currWord.compare(PqlKeyword::KEYWORD_IF) == 0) {
			//execute if
		}
		else if (currWord.compare(PqlKeyword::KEYWORD_PROCEDURE) == 0) {
			//execute procedure
		}
		else if (currWord.compare(PqlKeyword::KEYWORD_VARIABLE) == 0) {
			//execute variable
		}
		else if (currWord.compare(PqlKeyword::KEYWORD_CONSTANT) == 0) {
			//execute constant
		}
		else if (currWord.compare(PqlKeyword::KEYWORD_PROGLINE) == 0) {
			//execute program line
		}
	}
	else {
		isSuccess = false;
	}

	return isSuccess;
}

vector<string> PqlEngine::separateQuery(string query)
{
	istringstream sstream(query);
	vector<string> separatedQuery;

	while (sstream)
	{
		string currLine;
		if (!getline(sstream, currLine, ';'))
		{
			break;
		}
		separatedQuery.push_back(currLine);
	}

	return separatedQuery;
}

string PqlEngine::fixWhitespace(string unfixed)
{
	string cleaned;
	regex rSpace("\\s+");
	regex rSpaceComma("\\s+,");
	regex rCommaSpace(",\\s+");

	cleaned = regex_replace(unfixed, rSpace, " ");
	cleaned = regex_replace(cleaned, rSpaceComma, ",");
	cleaned = regex_replace(cleaned, rCommaSpace, ", ");

	return cleaned;
}

