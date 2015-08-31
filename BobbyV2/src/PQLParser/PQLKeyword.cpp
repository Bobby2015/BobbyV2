#include "PQLKeyword.h"

#include <map>

using namespace std;

map<string, bool> functionKeywordMap;
map<string, int> keywordMap;

//Constructor
PqlKeyword::PqlKeyword()
{
	buildFunctionKeywordMap();
	buildKeywordMap();
}

//Destructor
PqlKeyword::~PqlKeyword()
{
	
}

bool PqlKeyword::isFunctionKeywordExist(string keywordQuery)
{
	bool isFound = false;
	auto search = functionKeywordMap.find(keywordQuery);

	if (search != functionKeywordMap.end())
	{
		isFound = true;
	}

	return isFound;
}

void PqlKeyword::buildFunctionKeywordMap()
{
	functionKeywordMap[FN_CALLS] = true;
	functionKeywordMap[FN_CALLS_STAR] = true;
	functionKeywordMap[FN_MODIFIES] = true;
	functionKeywordMap[FN_USES] = true;
	functionKeywordMap[FN_FOLLOWS] = true;
	functionKeywordMap[FN_FOLLOWS_STAR] = true;
	functionKeywordMap[FN_PARENT] = true;
	functionKeywordMap[FN_PARENT_STAR] = true;
	functionKeywordMap[FN_NEXT] = true;
	functionKeywordMap[FN_NEXT_STAR] = true;
	functionKeywordMap[FN_AFFECTS] = true;
	functionKeywordMap[FN_AFFECTS_STAR] = true;

}

void PqlKeyword::buildKeywordMap()
{
	//build keyword map with index
}
