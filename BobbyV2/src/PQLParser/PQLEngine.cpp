#include "PQLEngine.h"

#include <string>
#include <sstream>
#include <iostream>
#include <regex>

using namespace std;

//Constructor
PqlEngine::PqlEngine()
{
	pqlKeyword = PqlKeyword();
}

//Destructor
PqlEngine::~PqlEngine()
{
	resetVariableList();
}

bool PqlEngine::executeQuery(string query) 
{

	bool isSuccess = false;

	isSuccess = validateQuery(query);
	
	if (isSuccess == true)
	{
		resetVariableList();
		parseQuery(query);
	}

	return isSuccess;
}

void PqlEngine::resetVariableList()
{
	variableList.clear();
	queryVariableList.clear();
	queryFunctionList.clear();
}

bool PqlEngine::validateQuery(string query)
{
	PQLValidator pqlValidator;

	bool isSuccess = pqlValidator.validateQuery(query);

	return isSuccess;
}

bool PqlEngine::parseQuery(string query)
{
	bool isSuccess = false;
	string cleanedQuery = fixWhitespace(query);
	vector <string> separatedQuery = separateQuery(cleanedQuery);

	for (int i = 0; i < separatedQuery.size(); i++)
	{
		string currQuery = separatedQuery[i];
		bool isSuccess = parseSingleQuery(currQuery);
	}

	//print out the values in variableList (for verification)
	cout << "----------Contents of variableList----------" << endl << endl;
	for (int i = 0; i < variableList.size(); i++)
	{
		pair <string, string> currPair;
		currPair = variableList[i];
		cout << i << ": <" << currPair.first << " - " << currPair.second << ">" << endl;
	}
	cout << endl;

	cout << "----------Contents of queryVariableList----------" << endl << endl;
	for (int i = 0; i < queryVariableList.size(); i++)
	{
		cout << "query variable : " << queryVariableList[i] << endl;
	}
	cout << endl;

	cout << "----------Contents of queryFunctionList----------" << endl << endl;
	for (int i = 0; i < queryFunctionList.size(); i++)
	{
		cout << "function : <<" << queryFunctionList[i].first.first << ", " << queryFunctionList[i].first.second << "> , <" << queryFunctionList[i].second.first << ", " << queryFunctionList[i].second.second << ">" <<  ">" << endl;
	}
	cout << endl;
	//end of printing statements (for verification)

	return isSuccess;
}

bool PqlEngine::parseSingleQuery(string query)
{
	bool isSuccess = false;
	string currWord;
	istringstream stream(query);

	stream >> currWord;
	bool isKeyword = pqlKeyword.isKeywordExist(currWord);

	if (isKeyword)
	{
		string remainingValue;
		getline(stream, remainingValue);

		if (currWord.compare(PqlKeyword::KEYWORD_SELECT) == 0) {
			isSuccess =parseSelectQuery(remainingValue);
		}
		else if (currWord.compare(PqlKeyword::KEYWORD_STMT) == 0) {
			isSuccess = parseVarQuery(PqlKeyword::KEYWORD_STMT, remainingValue);
		}
		else if (currWord.compare(PqlKeyword::KEYWORD_ASSIGN) == 0) {
			isSuccess = parseVarQuery(PqlKeyword::KEYWORD_ASSIGN, remainingValue);
		}
		else if (currWord.compare(PqlKeyword::KEYWORD_WHILE) == 0) {
			isSuccess = parseVarQuery(PqlKeyword::KEYWORD_WHILE, remainingValue);
		}
		else if (currWord.compare(PqlKeyword::KEYWORD_IF) == 0) {
			isSuccess = parseVarQuery(PqlKeyword::KEYWORD_IF, remainingValue);
		}
		else if (currWord.compare(PqlKeyword::KEYWORD_PROCEDURE) == 0) {
			isSuccess = parseVarQuery(PqlKeyword::KEYWORD_PROCEDURE, remainingValue);
		}
		else if (currWord.compare(PqlKeyword::KEYWORD_VARIABLE) == 0) {
			isSuccess = parseVarQuery(PqlKeyword::KEYWORD_VARIABLE, remainingValue);
		}
		else if (currWord.compare(PqlKeyword::KEYWORD_CONSTANT) == 0) {
			isSuccess = parseVarQuery(PqlKeyword::KEYWORD_CONSTANT, remainingValue);
		}
		else if (currWord.compare(PqlKeyword::KEYWORD_PROGLINE) == 0) {
			isSuccess = parseVarQuery(PqlKeyword::KEYWORD_PROGLINE, remainingValue);
		}
	}
	else {
		isSuccess = false;
	}

	return isSuccess;
}

bool PqlEngine::parseVarQuery(string varType, string query)
{
	bool isSuccess = false;
	
	istringstream stream(query);
	string varName;

	while (stream >> varName)
	{
		pair <string, string> currVarPair;
		currVarPair = make_pair(varType, varName);
		variableList.push_back(currVarPair);
	}

	return isSuccess;
}

bool PqlEngine::parseSelectQuery(string query)
{
	bool isSuccess = false;

	istringstream stream(query);
	string currWord;
	bool isVariableClause = true;

	while (stream >> currWord)
	{
		bool isKeyword = pqlKeyword.isKeywordExist(currWord);

		if (isKeyword)
		{
			if (currWord.compare(PqlKeyword::KEYWORD_SUCH) == 0 || currWord.compare(PqlKeyword::KEYWORD_THAT) == 0)
			{
				isVariableClause = false;
			}
		}
		else {
			if (isVariableClause == true)
			{
				queryVariableList.push_back(currWord);
			}
			else {
				string remainingValue;
				getline(stream, remainingValue);
				string functionWithVal = currWord + " " + remainingValue;
				isSuccess = parseSelectQueryFunction(functionWithVal);
			}
		}
	}

	return isSuccess;
}

bool PqlEngine::parseSelectQueryFunction(string query)
{
	bool isSuccess = false;

	istringstream stream(query);
	string currWord, currFunction, valueFirst, valueSecond;

	while (stream >> currWord)
	{
		bool isFunctionKeyword = pqlKeyword.isFunctionKeywordExist(currWord);

		if (isFunctionKeyword)
		{
			currFunction = currWord;
			string patternVar = "";
			bool isFirst = true;
			bool isOpenParanthesis = false;

			while (stream >> currWord)
			{
				if (currWord.compare(PqlKeyword::KEYWORD_OPEN_PARANTHESIS) == 0)
				{
					isOpenParanthesis = true;
				}
				else if (currWord.compare(PqlKeyword::KEYWORD_CLOSE_PARANTHESIS) == 0)
				{
					break;
				}
				else if (currFunction.compare(PqlKeyword::FN_PATTERN) == 0 && !isOpenParanthesis)
				{
					patternVar = currWord;
				}
				else 
				{
					if (isFirst == true)
					{
						valueFirst = currWord;
						isFirst = false;
					}
					else
					{
						valueSecond = currWord;
					}
				}
			}

			pair <string, string> currFunctionPair;
			pair <string, string> currValuePair;
			pair <pair<string, string>, pair<string, string>> currFunctionValuePair;
			currFunctionPair = make_pair(currFunction, patternVar);
			currValuePair = make_pair(valueFirst, valueSecond);
			currFunctionValuePair = make_pair(currFunctionPair, currValuePair);
			queryFunctionList.push_back(currFunctionValuePair);
		}

		isSuccess = true;
	}

	return isSuccess;
}

vector<string> PqlEngine::separateQuery(string query)
{
	istringstream sstream(query);
	vector<string> separatedQuery;

	while (sstream)
	{
		string currLine;
		if (!getline(sstream, currLine, ';'))
		{
			break;
		}
		separatedQuery.push_back(currLine);
	}

	return separatedQuery;
}

string PqlEngine::evaluateQuery()
{
	string queryAnswer = "";



	return queryAnswer;
}

string PqlEngine::fixWhitespace(string unfixed)
{
	string cleaned;
	regex rComma(",");
	regex rOpenParanthesis("\\(");
	regex rCloseParanthesis("\\)");
	regex rSpace("\\s+");

	cleaned = regex_replace(unfixed, rComma, " ");
	cleaned = regex_replace(cleaned, rOpenParanthesis, " ( ");
	cleaned = regex_replace(cleaned, rCloseParanthesis, " ) ");
	cleaned = regex_replace(cleaned, rSpace, " ");

	return cleaned;
}


