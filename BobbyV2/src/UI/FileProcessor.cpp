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

//-----------------//
// Opening of File //
//-----------------//

bool FileProcessor::fileExists(std::string fileName)
{
	struct stat buffer;
	return (stat(fileName.c_str(), &buffer) == 0);
}

void FileProcessor::attemptToOpenFile(std::string fileName)
{
	if (!fileExists(fileName)) 
	{
		std::cout << "File does not exist!" << std::endl;
	}

	else 
	{
		std::cout << "Processing contents of " + fileName + "..." << std::endl;
		
		std::ifstream infile(fileName);
		std::vector<char> fileContents((std::istreambuf_iterator<char> (infile)), (std::istreambuf_iterator<char>()));

		// testing for proper file reading --- to be removed
		/////////////////////////////////////////////////////////////////
		for (auto i = fileContents.begin(); i != fileContents.end(); ++i)
		{
			std::cout << *i;
		}

		std::cout << std::endl;
		/////////////////////////////////////////////////////////////////
	}
}

