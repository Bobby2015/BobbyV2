#ifndef UI_CLI_H
#define UI_CLI_H

#include <string>
#include <iostream>
#include "../UI/FileProcessor.h"
#include "../Parser/Parser.h"

class CLI
{
	public:
		// enum for user input options
		enum UserInputOptions : int
		{
			PARSE_PROGRAM_FILE = 1,
			MAKE_QUERY,
			DISPLAY_FILE_CONTENTS,
			EXIT_PROGRAM
		};

		// constructor and destructor
		CLI();
		~CLI();

		// main program loop
		void startProgramLoop();

		// menu display
		void displayMenu();

		// user input processing
		int promptUserForInput();
		void processUserInput(int);

		// SPA menu options
		void parseProgSrcFile();
		void makeQuery();
		void displayFileContents();
		void exitProgram();

		// getters and setters
		void setExitFlag(bool);
		bool getExitFlag();

	private:
		FileProcessor fileProcessor;
		Parse parser;

		bool exitFlag;
};

#endif 