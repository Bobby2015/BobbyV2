#include "PQLEngine.h"
#include <string>

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
	

	return isSuccess;
}

bool PqlEngine::validateQuery(string query)
{
	PQLValidator pqlValidator;

	bool isSuccess = pqlValidator.validateQuery(query);

	return isSuccess;
}

