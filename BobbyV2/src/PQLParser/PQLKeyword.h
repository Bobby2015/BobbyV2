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

	//Function Keywords
	static const string FN_CALLS;
	static const string FN_CALLS_STAR;
	static const string FN_MODIFIES;
	static const string FN_USES;
	static const string FN_FOLLOWS;
	static const string FN_FOLLOWS_STAR;
	static const string FN_PARENT;
	static const string FN_PARENT_STAR;
	static const string FN_NEXT;
	static const string FN_NEXT_STAR;
	static const string FN_AFFECTS;
	static const string FN_AFFECTS_STAR;

	//Keywords
	static const string KEYWORD_STMT;
	static const string KEYWORD_ASSIGN;
	static const string KEYWORD_WHILE;
	static const string KEYWORD_IF;
	static const string KEYWORD_PROCEDURE;
	static const string KEYWORD_VARIABLE;
	static const string KEYWORD_CONSTANT;
	static const string KEYWORD_PROGLINE;
	static const string KEYWORD_SELECT;
	static const string KEYWORD_SUCH_THAT;
	static const string KEYWORD_PATTERN;
	static const string KEYWORD_WITH;
	static const string KEYWORD_AND;

private:
	void buildFunctionKeywordMap();
	void buildKeywordMap();
	void buildSelectSequenceMap();

}; // PqlKeyword

#endif //PQLPARSER_PQLKEYWORD_H

#pragma once
