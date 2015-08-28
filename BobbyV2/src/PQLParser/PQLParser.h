#ifndef PQLPARSER_PQLPARSER_H
#define PQLPARSER_PQLPARSER_H

#include <string>

class PqlParserFacade
{
public:
	PqlParserFacade();
	~PqlParserFacade();
	bool executeQuery(std::string query);

private:

}; // PqlParserFacade

#endif  // PQLPARSER_PQLPARSER_H

#pragma once
