
#ifndef UI_CLI_H
#define UI_CLI_H

#include <string>
#include <iostream>
#include <fstream>

class CLI
{
	public:
		CLI();
		~CLI();

		void startProgramLoop();
		std::string promptUserForInput();
		void processUserInput(std::string);

		void setExitFlag(bool);
		bool getExitFlag();

		void exitProgram();
		
	private:
		bool exitFlag;
		static const std::string MESSAGE_PROMPT_FOR_INPUT;

		static const std::string USER_INPUT_EXIT;
};

#endif 