#include "CLI.h"

//-------------//
// Constructor //
//-------------//

CLI::CLI()
{
	setExitFlag(false);
}

//------------//
// Destructor //
//------------//

CLI::~CLI()
{

}

//-------------------//
// Main Program Loop //
//-------------------//

void CLI::startProgramLoop()
{
	while (!exitFlag)
	{
		promptUserForProgSrcFile();
	}
}

//--------------//
// User Prompts //
//--------------//

void CLI::promptUserForProgSrcFile() 
{
	std::string userInput;
	std::cout << "Enter file path of program source (type \"exit\" to quit the program): " ;
	std::getline (std::cin, userInput);
}

void CLI::processUserInput(std::string userInput)
{
	if (userInput == "exit") 
	{
		exitProgram();
	} 

	else
	{
		
	}
}

void CLI::exitProgram()
{
	setExitFlag(true);
}

//------------------------//
// Attribute Modification //
//------------------------//

void CLI::setExitFlag(bool flag)
{
	exitFlag = flag;
}

//------------------//
// Attribute Access //
//------------------//

bool CLI::getExitFlag()
{
	return exitFlag;
}