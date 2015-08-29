#include "../UI/FileProcessor.h"
#include <string>

using namespace std;

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

bool FileProcessor::fileExists(string &fileName)
{
	struct stat buffer; // stat represents file status
	return (stat(fileName.c_str(), &buffer) == 0);
}

//-----------------------------//
// Conversion of File Contents //
//-----------------------------//

string FileProcessor::copyFileContentsToString(string &fileName)
{

	if (!fileExists(fileName))
	{
		cout << "[FileProcessor] File does not exist!" << endl;
	}

	else
	{
		cout << "[FileProcessor] Processing contents of " + fileName + "..." << endl;

		ifstream in(fileName, ios::in | ios::binary);
		if (in)
		{
			string contents;
			in.seekg(0, ios::end);
			contents.resize(in.tellg());
			in.seekg(0, ios::beg);
			in.read(&contents[0], contents.size());
			in.close();

			return contents;
		}
		else
			throw(errno);
	}
}


