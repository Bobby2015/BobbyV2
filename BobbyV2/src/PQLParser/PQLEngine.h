#ifndef PQLPARSER_PQLENGINE_H
#define PQLPARSER_PQLENGINE_H

#include <string>

#include "PQLValidator.h"

class PqlEngine
{
public:
	PqlEngine();
	~PqlEngine();
	bool executeQuery(std::string);
	
private:
	bool validateQuery(std::string);

}; // PqlEngine

#endif  // PQLPARSER_PQLENGINE_H

#pragma once
