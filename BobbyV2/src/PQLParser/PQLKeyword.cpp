#include "PQLKeyword.h"

#include <map>
#include <iostream>

using namespace std;

map<string, bool> functionKeywordMap;
map<string, bool> keywordMap;
map<string, int*> selectSequenceMap;

//Function Keywords
static const string FN_CALLS = "Calls";
static const string FN_CALLS_STAR = "Calls*";
static const string FN_MODIFIES = "Modifies";
static const string FN_USES = "Uses";
static const string FN_FOLLOWS = "Follows";
static const string FN_FOLLOWS_STAR = "Follows*";
static const string FN_PARENT = "Parent";
static const string FN_PARENT_STAR = "Parent*";
static const string FN_NEXT = "Next";
static const string FN_NEXT_STAR = "Next*";
static const string FN_AFFECTS = "Affects";
static const string FN_AFFECTS_STAR = "Affects*";

//Keywords
static const string KEYWORD_STMT = "stmt";
static const string KEYWORD_ASSIGN = "assign";
static const string KEYWORD_WHILE = "while";
static const string KEYWORD_IF = "if";
static const string KEYWORD_PROCEDURE = "procedure";
static const string KEYWORD_VARIABLE = "variable";
static const string KEYWORD_CONSTANT = "constant";
static const string KEYWORD_PROGLINE = "prog_line";
static const string KEYWORD_SELECT = "select";
static const string KEYWORD_SUCH_THAT = "such that";
static const string KEYWORD_PATTERN = "pattern";
static const string KEYWORD_WITH = "with";
static const string KEYWORD_AND = "and";

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
