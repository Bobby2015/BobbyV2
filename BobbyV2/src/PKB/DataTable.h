#pragma once

#ifndef PKB_DATATABLE_H
#define PKB_DATATABLE_H

#include <map>

using namespace std;
// include all the table process
class TableWrapper
{
public:


private:


}; //TableWrapper

// Map variables to an ID
class VarMapTable
{
public:

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
		int lineNo;
		int modifies;
		int uses;
	};
	// Key - varID
	map<int, values> varTableMap;
}; // VarTable


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

class ModTableVar
{
public:

private:
}; // ModTableVar

class ModTableLine
{
public:

private:
}; // ModTableLine

class UsesTableVar
{
public:

private:
}; // UsesTableVar

class UsesTableLine
{
public:

private:
}; // UsesTableLine

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

#endif // PKB_DATATABLE_H
