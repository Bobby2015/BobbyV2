#include "DataTable.h"

using namespace DataTables;
//------------------------//
// TableWrapper functions //
//------------------------//

TableWrapper::TableWrapper()
{
}

VarMapTable TableWrapper::getVMapTable()
{
	return vMapTable;
}

VarTable TableWrapper::getVarTable()
{
	return vTable;
}

//-----------------------//
// VarMapTable functions //
//-----------------------//

VarMapTable::VarMapTable()
{
}
VarMapTable::~VarMapTable()
{
}

const map<string, int> VarMapTable::getMap()
{
	return varMap;
}


VarTable::VarTable()
{

}

VarTable::~VarTable()
{

}


