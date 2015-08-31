#include "PQLKeyword.h"

#include <map>

using namespace std;

map<string, bool> functionKeywordMap;
map<string, bool> keywordMap;
map<string, int*> selectSequenceMap;

//Constructor
PqlKeyword::PqlKeyword()
{
	buildFunctionKeywordMap();
	buildKeywordMap();
	buildSelectSequenceMap();
}

//Destructor
PqlKeyword::~PqlKeyword()
{
	
}

bool PqlKeyword::isFunctionKeywordExist(string keywordQuery)
{
	bool isFound = false;
	auto search = keywordMap.find(keywordQuery);

	if (search != keywordMap.end())
	{
		isFound = true;
	}

	return isFound;
}

bool PqlKeyword::isValidKeywordSequence(vector<string> keywordList)
{
	bool isFound = false;
	
	//check if the keyword sequence is correct

	return isFound;
}

bool PqlKeyword::isKeywordExist(string keywordQuery)
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
	keywordMap[KEYWORD_STMT] = true;
	keywordMap[KEYWORD_ASSIGN] = true;
	keywordMap[KEYWORD_WHILE] = true;
	keywordMap[KEYWORD_IF] = true;
	keywordMap[KEYWORD_PROCEDURE] = true;
	keywordMap[KEYWORD_VARIABLE] = true;
	keywordMap[KEYWORD_CONSTANT] = true;
	keywordMap[KEYWORD_PROGLINE] = true;
	keywordMap[KEYWORD_SELECT] = true;
}

void PqlKeyword::buildSelectSequenceMap()
{
	int foo[5];
	int* bar = foo;
	selectSequenceMap[KEYWORD_SELECT] = bar;

	
	
	
	//selectSequenceMap[KEYWORD_SUCH_THAT] = int[]{ 2, 3 };
	
	
	static const string KEYWORD_SUCH_THAT = "such that";
	static const string KEYWORD_PATTERN = "pattern";
	static const string KEYWORD_WITH = "with";
	static const string KEYWORD_AND = "and";
}
