#include "CLI.h"

//-------------//
// Constructor //
//-------------//

CLI::CLI()
{
	const std::string MESSAGE_PROMPT_FOR_INPUT = "Enter file path of program source (type \"exit\" to quit the program): ";
	const std::string USER_INPUT_EXIT = "exit";
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
		std::string userInput = promptUserForInput();
		processUserInput(userInput);
	}
}

//--------------//
// User Prompts //
//--------------//

std::string CLI::promptUserForInput() 
{
	std::string userInput;
	std::cout << MESSAGE_PROMPT_FOR_INPUT;
	std::getline (std::cin, userInput);
	return userInput;
}

void CLI::processUserInput(std::string userInput)
{
	if (userInput == USER_INPUT_EXIT) 
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