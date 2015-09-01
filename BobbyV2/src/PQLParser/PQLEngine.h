#ifndef PQLPARSER_PQLENGINE_H
#define PQLPARSER_PQLENGINE_H

#include <string>
#include <stdlib.h>

#include "PQLValidator.h"
#include "PQLKeyword.h"

using namespace std;

class PqlEngine
{
public:
	PqlEngine();
	~PqlEngine();
	bool executeQuery(string);
	
private:
	PqlKeyword pqlKeyword;
	vector<pair<string, string>> variableList;

	bool validateQuery(string);
	bool evaluateQuery(string);
	bool identifySingleQuery(string);
	bool evaluateAssignQuery(string);
	vector<string> separateQuery(string);
	string fixWhitespace(string);

}; // PqlEngine

#endif  // PQLPARSER_PQLENGINE_H

#pragma once
