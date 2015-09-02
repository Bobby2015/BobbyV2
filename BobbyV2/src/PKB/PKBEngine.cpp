#include "PKBEngine.h"
#include "DataTable.h"

#include <vector>
#include <string>


using namespace PKBEngine;

QueryEngine::QueryEngine()
{

}

QueryEngine::~QueryEngine()
{

}

//FOR CALLS - START
vector<string> QueryEngine::getCalls(string prod, int select) //select procedure which call by prod
{
	vector<string> list;
	list.push_back("empty");

	return list;
}

vector<string> QueryEngine::getCalls(int select, string prod) //select procedure that call prod
{
	vector<string> list;
	list.push_back("empty");

	return list;
}

vector<string> QueryEngine::getCalls() //select all the procedure
{
	vector<string> list;
	list.push_back("empty");

	return list;
}


bool QueryEngine::getCalls(string prod1, string prod2) // comepare wether prod1 calls prod2
{
	bool isCall = false;


	return isCall;
}
// FOR CALLS - END

// FOR MODIFIES - START
vector<string>  QueryEngine::getModifies(int select, string var) //select statement# that modifies var
{
	vector<string> list;
	list.push_back("empty");
	
	
	DataTables::TableWrapper table;

	//get var map table
	DataTables::VarMapTable varMapTable=table.getVMapTable();

	//get vartable
	DataTables::VarTable varTable = table.getVarTable();

	//get statement line
	map<string,int> mapObj =  varMapTable.getMap();
	int index = mapObj.at(var);

	

	//store in vector

	//return
	return list;
}
vector<string>  QueryEngine::getModifies(string stmt, int select) //select var that modifies in stmt#
{
	vector<string> list;
	list.push_back("empty");
	//get stmt table

	//get var from stmt stable

	//store in vector

	//return
	return list;

}
bool  QueryEngine::getModifiesProd(string prod, string var) // check wether procedure modifies var
{
	bool isModify = false;


	return isModify;
}
bool  QueryEngine::getModifiesStmt(string stmt, string var) // check wether stmt# modifies var
{
	bool isModify = false;


	return isModify;
}
// FOR MODIFIFES -END

// FOR FILTER - START
vector<string>QueryEngine::assignStatement(vector<string>list) //filter list to contain assign statement only
{
	
	list.push_back("empty");

	return list;
}
vector<string>QueryEngine::containerStatement(vector<string>list) //filter list to contain container statement only
{
	
	list.push_back("empty");

	return list;
}

vector<string>QueryEngine::callStament(vector<string>list) //filter list to contain call statement only
{
	
	list.push_back("empty");

	return list;
}
// FOR FILTER - END


StorageEngine::StorageEngine()
{



}

StorageEngine::~StorageEngine()
{


}