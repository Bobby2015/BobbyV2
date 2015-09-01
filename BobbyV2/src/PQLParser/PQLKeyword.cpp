#include "PQLKeyword.h"

#include <map>
#include <iostream>

using namespace std;

map<string, bool> functionKeywordMap;
map<string, bool> keywordMap;
map<string, int*> selectSequenceMap;

//Function Keywords
const string PqlKeyword::FN_CALLS = "Calls";
const string PqlKeyword::FN_CALLS_STAR = "Calls*";
const string PqlKeyword::FN_MODIFIES = "Modifies";
const string PqlKeyword::FN_USES = "Uses";
const string PqlKeyword::FN_FOLLOWS = "Follows";
const string PqlKeyword::FN_FOLLOWS_STAR = "Follows*";
const string PqlKeyword::FN_PARENT = "Parent";
const string PqlKeyword::FN_PARENT_STAR = "Parent*";
const string PqlKeyword::FN_NEXT = "Next";
const string PqlKeyword::FN_NEXT_STAR = "Next*";
const string PqlKeyword::FN_AFFECTS = "Affects";
const string PqlKeyword::FN_AFFECTS_STAR = "Affects*";

//Keywords
const string PqlKeyword::KEYWORD_STMT = "stmt";
const string PqlKeyword::KEYWORD_ASSIGN = "assign";
const string PqlKeyword::KEYWORD_WHILE = "while";
const string PqlKeyword::KEYWORD_IF = "if";
const string PqlKeyword::KEYWORD_PROCEDURE = "procedure";
const string PqlKeyword::KEYWORD_VARIABLE = "variable";
const string PqlKeyword::KEYWORD_CONSTANT = "constant";
const string PqlKeyword::KEYWORD_PROGLINE = "prog_line";
const string PqlKeyword::KEYWORD_SELECT = "select";
const string PqlKeyword::KEYWORD_SUCH_THAT = "such that";
const string PqlKeyword::KEYWORD_PATTERN = "pattern";
const string PqlKeyword::KEYWORD_WITH = "with";
const string PqlKeyword::KEYWORD_AND = "and";

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
	auto search = functionKeywordMap.find(keywordQuery);

	if (search != functionKeywordMap.end())
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
	auto search = keywordMap.find(keywordQuery);

	if (search != keywordMap.end())
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

	keywordMap[KEYWORD_SUCH_THAT] = true;
	keywordMap[KEYWORD_PATTERN] = true;
	keywordMap[KEYWORD_WITH] = true;
	keywordMap[KEYWORD_AND] = true;
}

void PqlKeyword::buildSelectSequenceMap()
{
	//int foo[5];
	//int* bar = foo;
	//selectsequencemap[keyword_select] = bar;

	//
	//
	//
	//selectsequencemap[keyword_such_that] = int[]{ 2, 3 };
	//
	//
	//static const string keyword_such_that = "such that";
	//static const string keyword_pattern = "pattern";
	//static const string keyword_with = "with";
	//static const string keyword_and = "and";
}
