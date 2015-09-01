#ifndef PQLPARSER_PQLPARSER_H
#define PQLPARSER_PQLPARSER_H

#include <string>

#include "PQLEngine.h"

using namespace std;

class PqlParserFacade
{
public:
	PqlParserFacade();
	~PqlParserFacade();
	bool executeQuery(string);

private:

}; // PqlParserFacade

#endif  // PQLPARSER_PQLPARSER_H

#pragma once
