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
	string s1;

	while (stream >> s1)
	{
		cout << s1 << endl;
	}

	return isSuccess;
}

