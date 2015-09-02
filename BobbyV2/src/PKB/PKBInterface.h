#pragma once

#ifndef PKB_PKBINTERFACE_H
#define PKB_PKBINTERFACE_H

#include<string>
#include<vector>

using namespace std;

namespace PKBInterface
{
	//Interface for query
	class QueryInterface
	{
	public:
		QueryInterface();
		~QueryInterface();
		 //for Calls
		vector<string> getCalls(pair<string,string> procedure1,pair<string,string> procedure2); // return list of procedure name . eg, "first"
		vector<string> getAllCalls(); // return list of all procedure name.
		bool compareCalls(string procedure1, string procedure2);  // check wether prod1 calls prod2 , return boolean
		//for Modifies
		vector<string> getModifies(pair<string, string>, pair<string, string>);
		bool compareModifies(string stmt1, string var1); // check wether stmt1 modifies var1
		
		// for Uses
		//vector<string> getModifies(pair<string, string>, pair<string, string>);
		//bool compareModifies(string stmt1, string var1); // check wether stmt1 modifies var1

	private:


	};


	//Interface for storage
	class StorageInterface
	{
	public:
	

	private:



	};



}//namespace PKB

#endif //PKB_PKBINTERFACE_H