#pragma once

#ifndef FILE_PROCESSOR_H
#define FILE_PROCESSOR_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sys/stat.h>

class FileProcessor
{
	public:
		// Constructor and Destructor
		FileProcessor();
		~FileProcessor();

		// File initialization
		void attemptToOpenFile(std::string fileName);
		bool fileExists(std::string fileName);
				
	private:

};

#endif