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

		std::ifstream infile(fileName); //opening an input stream for file test.txt
		std::vector<char> fileContents((std::istreambuf_iterator<char>(infile)), (std::istreambuf_iterator<char>()));
		
		return fileContents;
	}
}

std::string FileProcessor::copyFileContentsToString(std::string &fileName)
{

	if (!fileExists(fileName))
	{
		std::cout << "File does not exist!" << std::endl;
	}

	else
	{
		std::cout << "Processing contents of " + fileName + "..." << std::endl;

		std::ifstream in(fileName, std::ios::in | std::ios::binary);
		if (in)
		{
			std::string contents;
			in.seekg(0, std::ios::end);
			contents.resize(in.tellg());
			in.seekg(0, std::ios::beg);
			in.read(&contents[0], contents.size());
			in.close();

			/*
			std::string str2("procedure");
			std::size_t found = contents.find(str2);

			if (found != std::string::npos)
				std::cout << "first 'procedure' found at: " << found << '\n';
			found = contents.find("procedure", found + 1, 6);
			if (found != std::string::npos)
				std::cout << "second 'procedure' found at: " << found << '\n';
			*/
			std::string delimiter = "\n";

			size_t pos = 0;
			std::string token;
			while ((pos = contents.find(delimiter)) != std::string::npos) {
				token = contents.substr(0, pos);
				std::cout << token << std::endl;
				contents.erase(0, pos + delimiter.length());
			}
			std::cout << contents << std::endl;

			return contents;
		}
		else
			throw(errno);
	}
}


