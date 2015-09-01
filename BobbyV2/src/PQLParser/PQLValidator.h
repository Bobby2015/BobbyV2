#ifndef PQLPARSER_PQLVALIDATOR_H
#define PQLPARSER_PQLVALIDATOR_H

#include <string>
#include <regex>

using namespace std;

class PQLValidator
{
public:
	bool validateQuery(string);

private:
	bool syntaxValidator(string);
	bool semanticValidator(string);

}; //PQLValidator

#endif  // PQLPARSER_PQLVALIDATOR_H
#pragma once
