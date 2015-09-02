#include "PKBInterface.h"
#include "DataTable.h"

#include<string>
#include<vector>

using namespace PKBInterface;
using namespace std;

QueryInterface::QueryInterface()
{

}

QueryInterface::~QueryInterface()
{

}

// FOR CALLS - START
vector<string> QueryInterface::getCalls(pair<string, string> procedure1, pair<string, string> procedure2)
{
	vector<string> procedureList;
	procedureList.push_back("eempty");

	//2 cases here (p, "prod"), ("prod", p)

	return procedureList;
}

vector<string> QueryInterface::getAllCalls()
{
	vector<string> procedureList;
	procedureList.push_back("eempty");
	//return all procedure

	return procedureList;

}

bool QueryInterface::compareCalls(string procedure1, string procedure2)
{
	bool isCall = false;



	return isCall;
}
// FOR CALLS - END

// FOR MODIFIES - START
//<string1, string2>
//string1 : assign, "procedure", stmt(if/while) , var, wildcard
//string2 : predef or select

vector<string> QueryInterface::getModifies(pair<string, string> pair1, pair<string, string> pair2)
{
	vector<string> procedureList;
	procedureList.push_back("eempty");
	if (pair1.second == "predef")
	{
		

	}
	if (pair2.second == "predef")
	{


	}
	return procedureList;
}

bool QueryInterface::compareModifies(string stmt1, string var1) 
{
	//total 2 type of comparison
	// "procedure" vs var

	// stmt# vs var
	bool isModify = false;



	return isModify;

}

// FOR MODIFIES END