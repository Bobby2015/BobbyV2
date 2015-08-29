#include "../UI/CLI.h"
#include <string>

using namespace std;

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
	cout << "Select an option by entering one of the numbers below: " << endl;
	cout << "(1) Parse program source file" << endl;
	cout << "(2) Make a query to source file" << endl;
	cout << "(3) Display current source file" << endl;
	cout << "(4) Exit" << endl;
}

//-----------------------//
// User Input Processing //
//-----------------------//

int CLI::promptUserForInput() 
{
	int userInput;

	cin >> userInput;
	cin.ignore();
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
			cout << "invalid user input!" << endl;
			break;

	}
}

//------------------//
// SPA Menu Options //
//------------------//

void CLI::parseProgSrcFile()
{
	string fileName;
	FileProcessor fileProcessor;
	Parse parser;

	cout << "Enter program source file name: ";
	getline(cin, fileName);

	//vector<char> fileContents = fileProcessor.convertFileContentsToCharArray(fileName);
	string fileContentString = fileProcessor.copyFileContentsToString(fileName);
	parser.concreteSyntaxValidator(fileContentString);
	
	// insert code for file parsing
	cout << "Parsing file to Program Knowledge Base..." << endl;
	
	cout << endl;
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