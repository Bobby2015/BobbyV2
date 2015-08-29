#include "../UI/CLI.h"

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
		displayMenu();
		int userInput = promptUserForInput();
		processUserInput(userInput);
	}
}

void CLI::displayMenu()
{
	std::cout << "Select an option by entering one of the numbers below: " << std::endl;
	std::cout << "(1) Parse program source file" << std::endl;
	std::cout << "(2) Make a query to source file" << std::endl;
	std::cout << "(3) Display current source file" << std::endl;
	std::cout << "(4) Exit" << std::endl;
}

//-----------------------//
// User Input Processing //
//-----------------------//

int CLI::promptUserForInput() 
{
	int userInput;

	std::cin >> userInput;
	std::cin.ignore();
	return userInput;
}

void CLI::processUserInput(int userInput)
{
	switch (userInput)
	{
		case PARSE_PROGRAM_FILE:
			parseProgSrcFile();
			break;

		case MAKE_QUERY:
			makeQuery();
			break;

		case DISPLAY_FILE_CONTENTS:
			displayFileContents();
			break;

		case EXIT_PROGRAM:
			exitProgram();
			break;

		default:
			std::cout << "invalid user input!" << std::endl;
			break;

	}
}

//------------------//
// SPA Menu Options //
//------------------//

void CLI::parseProgSrcFile()
{
	std::string fileName;
	FileProcessor fileProcessor;
	Parse parser;

	std::cout << "Enter program source file name: ";
	std::getline(std::cin, fileName);

	std::vector<char> fileContents = fileProcessor.convertFileContentsToCharArray(fileName);
	std::string fileContentString = fileProcessor.copyFileContentsToString(fileName);
	
	// insert code for file parsing
	std::cout << "Parsing file to Program Knowledge Base..." << std::endl;
	
	std::cout << std::endl;
}

void CLI::makeQuery()
{
	// insert code here
}

void CLI::displayFileContents()
{
	// insert code here
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