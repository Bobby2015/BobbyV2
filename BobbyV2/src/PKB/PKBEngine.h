#pragma once

#ifndef PKB_PKBSTORAGEPROCESS_H
#define PKB_PKBSTORAGEPROCESS_H

#include<string>
#include<vector>

using namespace std;

namespace PKBEngine
{
	//For PQLParser to query
	class QueryEngine
	{
	public:
		QueryEngine();
		~QueryEngine();
		//for filter
		vector<string> assignStatement(vector<string>list);
		vector<string> containerStatement(vector<string>list);
		vector<string> callStament(vector<string>list);

		//for calls
		vector<string> getCalls(string prod, int select);
		vector<string> getCalls(int select, string prod);
		vector<string> getCalls();
		bool getCalls(string prod1, string prod2);

		//for modifies
		vector<string> getModifies(int select, string var);
		vector<string> getModifies(string stmt, int select);
		bool getModifiesProd(string prod, string var);
		bool getModifiesStmt(string stmt, string var);

		//for uses
		

	private:
		
		

	};


	//For Parser to store DataTable
	class StorageEngine
	{
	public:
		StorageEngine();
		~StorageEngine();

	private:
		


	};



}//namespace PKB

#endif //PKB_PKBSTORAGEPROCESS_H