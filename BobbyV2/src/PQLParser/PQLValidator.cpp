#include "PQLValidator.h"
#include <string>

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

	//stub
	isSuccess = true;

	return isSuccess;
}

bool PQLValidator::semanticValidator(string query)
{
	bool isSuccess = false;

	//stub
	isSuccess = true;

	return isSuccess;
}