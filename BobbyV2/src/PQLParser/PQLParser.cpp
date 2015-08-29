#include "PQLParser.h"
#include <string>

using namespace std;

//Constructor
PqlParserFacade::PqlParserFacade()
{

}

//Destructor
PqlParserFacade::~PqlParserFacade()
{

}

bool PqlParserFacade::executeQuery(string query) 
{

	bool isSuccess = false;

	PqlEngine pqlEngine;

	isSuccess = pqlEngine.executeQuery(query);

	return isSuccess;
}