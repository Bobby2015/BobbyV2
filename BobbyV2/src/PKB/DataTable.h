#pragma once

#ifndef PKB_DATATABLE_H
#define PKB_DATATABLE_H

#include <map>

using namespace std;
// include all the table process
namespace DataTables {

	// Map variables to an ID
	class VarMapTable
	{
	public:
		VarMapTable();
		~VarMapTable();
		const map<string, int> getMap();
	private:
		// Key - variable
		map<string, int> varMap;
	};

	// VarTable with mod/uses
	class VarTable
	{
	public:
		VarTable();
		~VarTable();

	private:
		struct values
		{
			int stmtNo;
			int modifies;
			int uses;
		};
		// Key - varID
		map<int, values> varTableMap;
	}; // VarTable

	class TableWrapper
	{
	public:
		TableWrapper();
		VarMapTable getVMapTable();
		VarTable getVarTable();

	private:
		VarMapTable vMapTable;
		VarTable vTable;

	}; //TableWrapper



	class ProcedureTable
	{
	public:
		ProcedureTable();
		~ProcedureTable();
	private:
		struct values
		{
			string processName;
			int minStatementNo;
			int maxStatementNo;
		};
		// Key - procedure ID
		map<int, values> procTableMap;
	}; // ProcedureTable

	class StatementTable
	{
	public:
		StatementTable();
		~StatementTable();
	private:
		enum STATEMENT_TYPE {
			ASSIGNMENT,
			IF,
			WHILE
			//etc will populate
		};
		struct values
		{
			STATEMENT_TYPE stmtType;
			string stmtLHS;
			string stmtRHS;
		};
		// Key - lineNo
		map<int, values> stmtTableMap;
	}; // StatementTable

	class ConstantTableValue
	{
	public:

	private:
		// Key - lineNo
		map<int, int> constTableMap;
	}; // ConstantTableValue

	class ConstantTableLine
	{
	public:

	private:
	}; // ConstantTableLine

	class CallsTableProc
	{
	public:

	private:
	}; // CallsTableProc

	class CallsTableLine
	{
	public:

	private:
	}; // CallsTableLine

	class FollowsTableNext
	{
	public:

	private:
	}; // FollowsTableNext

	   // I think only 1 table is enough tho
	class FollowsTablePrev
	{
	public:

	private:
	}; // FollowsTablePrev

	class NextTableNext
	{
	public:

	private:
	}; // NextTableNext

	   // same for this
	class NextTablePrev
	{
	public:

	private:
	}; // NextTablePrev

	   // this needs redesign i think
	class ParentTable
	{
	public:

	private:
	}; // ParentTable

	class ChildTable
	{
	public:

	private:
	}; // ChildTable
} // namespace DataTables
#endif // PKB_DATATABLE_H
