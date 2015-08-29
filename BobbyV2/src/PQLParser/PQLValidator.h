#ifndef PQLPARSER_PQLVALIDATOR_H
#define PQLPARSER_PQLVALIDATOR_H

#include <string>
#include <regex>

class PQLValidator
{
public:
	bool validateQuery(std::string);

private:
	bool syntaxValidator(std::string);
	bool semanticValidator(std::string);

}; //PQLValidator

#endif  // PQLPARSER_PQLVALIDATOR_H
#pragma once
