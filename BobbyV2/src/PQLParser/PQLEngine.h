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
	vector<string> queryVariableList;
	vector<pair<pair<string, string>, pair<string, string>>> queryFunctionList;

	void resetVariableList();
	bool validateQuery(string);
	bool parseQuery(string);
	bool parseSingleQuery(string);
	bool parseVarQuery(string, string);
	bool parseSelectQuery(string);
	bool parseSelectQueryFunction(string);
	string evaluateQuery();
	vector<string> separateQuery(string);
	string fixWhitespace(string);

}; // PqlEngine

#endif  // PQLPARSER_PQLENGINE_H

#pragma once
