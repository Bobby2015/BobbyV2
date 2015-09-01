#ifndef PQLPARSER_PQLKEYWORD_H
#define PQLPARSER_PQLKEYWORD_H

#include <string>
#include <vector>

using namespace std;

class PqlKeyword
{
public:
	PqlKeyword();
	~PqlKeyword();
	bool isFunctionKeywordExist(string);
	bool isKeywordExist(string);
	bool isValidKeywordSequence(vector<string>);

private:
	void buildFunctionKeywordMap();
	void buildKeywordMap();
	void buildSelectSequenceMap();

}; // PqlKeyword

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

#endif //PQLPARSER_PQLKEYWORD_H

#pragma once
