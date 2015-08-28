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

bool FileProcessor::fileExists(std::string &fileName)
{
	struct stat buffer;
	return (stat(fileName.c_str(), &buffer) == 0);
}

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
		std::vector<char> fileContents((std::istreambuf_iterator<char>(infile)), (std::istreambuf_iterator<char>()));
		return fileContents;
	}
}


