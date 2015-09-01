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
	std::vector<string> procedureList;

	//2 cases here (p, "prod"), ("prod", p)

	return procedureList;
}

vector<string> QueryInterface::getAllCalls()
{
	std::vector<string> procedureList;

	//return all procedure

	return procedureList;

}

bool QueryInterface::compareCalls(string procedure1, string procedure2)
{
	bool call = false;



	return call;
}
// FOR CALLS - END


// FOR MODIFIES - START
QueryInterface::~QueryInterface()
{

}






