#ifndef PQLPARSER_PQLENGINE_H
#define PQLPARSER_PQLENGINE_H

#include <string>

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
	bool validateQuery(string);
	bool evaluateQuery(string);

}; // PqlEngine

#endif  // PQLPARSER_PQLENGINE_H

#pragma once
