#include "PQLValidator.h"
#include <string>
#include <iostream>

using namespace std;

bool PQLValidator::validateQuery(string query) 
{
	bool isSuccess = false;

	bool isSuccessSyntax = syntaxValidator(query);
	bool isSuccessSemantic = semanticValidator(query);

	if ((isSuccessSyntax && isSuccessSemantic) == true) 
	{
		isSuccess = true;
	}

	return isSuccess;
}

bool PQLValidator::syntaxValidator(string query)
{
	bool isSuccess = false;

	query = query + ";\n";
	string delimiter = ";";
	size_t index = 0;
	string token;

	while ((index = query.find(delimiter)) != string::npos)
	{
		token = query.substr(0, index);

		smatch initializer;
		regex procedure();
	}
	

	return isSuccess;
}

bool PQLValidator::semanticValidator(string query)
{
	bool isSuccess = false;

	return isSuccess;
}