#include "../UI/FileProcessor.h"

//-------------//
// Constructor //
//-------------//

FileProcessor::FileProcessor()
{

}

//------------//
// Destructor //
//------------//

FileProcessor::~FileProcessor()
{

}

//----------------------------//
// Checking of File Existence //
//----------------------------//

bool FileProcessor::fileExists(std::string &fileName)
{
	struct stat buffer; // stat represents file status
	return (stat(fileName.c_str(), &buffer) == 0);
}

//-----------------------------//
// Conversion of File Contents //
//-----------------------------//

std::vector<char> FileProcessor::convertFileContentsToCharArray(std::string &fileName)
{
	if (!fileExists(fileName))
	{
		std::cout << "File does not exist!" << std::endl;
	}

	else 
	{
		std::cout << "Processing contents of " + fileName + "..." << std::endl;

		std::ifstream infile(fileName);
		std::string line;
		while (std::getline(infile, line)) // To get you all the lines.
		{
			std::cout << line; // Prints our STRING.
		}
		infile.close();
		std::vector<char> fileContents((std::istreambuf_iterator<char>(infile)), (std::istreambuf_iterator<char>()));
		
		return fileContents;
	}
}


