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

	bool isSuccessSyntax = concreteSyntaxValidator(query);

	if (isSuccessSyntax)
	{
		
	}

	return isSuccess;
}

bool PqlEngine::concreteSyntaxValidator(std::string query) 
{

	bool isSuccess = false;

	std::cout << "validating..";

	return isSuccess;
}