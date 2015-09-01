#include "PQLEngine.h"

#include <string>
#include <sstream>
#include <iostream>

using namespace std;

//Constructor
PqlEngine::PqlEngine()
{

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

	istringstream stream(query);
	PqlKeyword pqlKeyword;
	string currWord;

	while (stream >> currWord)
	{
		bool isKeyword = pqlKeyword.isKeywordExist(currWord);

		if (isKeyword)
		{
			if (currWord.compare(PqlKeyword::KEYWORD_SELECT) == 0) {
				cout << "it is a select statement";
			}
			else {

			}
			cout << currWord << endl;
		}
		
	}

	return isSuccess;
}

