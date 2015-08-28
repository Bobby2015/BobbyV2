#ifndef PQLPARSER_PQLENGINE_H
#define PQLPARSER_PQLENGINE_H

#include <string>


class PqlEngine
{
public:
	PqlEngine();
	~PqlEngine();
	bool executeQuery(std::string query);

private:

}; // PqlParserFacade

#endif  // PQLPARSER_PQLENGINE_H

#pragma once
