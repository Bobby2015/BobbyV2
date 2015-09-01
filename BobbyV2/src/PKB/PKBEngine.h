#pragma once

#ifndef PKB_PKBSTORAGEPROCESS_H
#define PKB_PKBSTORAGEPROCESS_H

#include<string>

using namespace std;

namespace PKB 
{
	//For PQLParser to query
	class QueryEngine
	{
	public:
		QueryEngine();
		~QueryEngine();

	private:
		//vector<string>::getCalls(string prod1, string prod2);
		
	

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