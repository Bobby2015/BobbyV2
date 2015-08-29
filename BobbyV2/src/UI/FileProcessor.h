#pragma once

#ifndef FILE_PROCESSOR_H
#define FILE_PROCESSOR_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sys/stat.h>

#include <iterator>

class FileProcessor
{
	public:
		// Constructor and Destructor
		FileProcessor();
		~FileProcessor();

		// Checking for file existence
		bool fileExists(std::string&);

		// Conversion of file content
		std::vector<char> convertFileContentsToCharArray(std::string&);

		// Conversion of file content
		std::string copyFileContentsToString(std::string&);
				
	private:

};

#endif