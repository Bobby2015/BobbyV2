#pragma once
#ifndef CLI_H
#define CLI_H

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
};

#endif 