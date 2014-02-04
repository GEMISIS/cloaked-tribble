#ifndef _FILE_H_
#define _FILE_H_
#include <fstream>

/*File is a wrapper for fstream
* Allows an ID to be assigned
*/
class File
{
public:
	File();
	File(char* path, char* ID);
	bool loadFile(char* path, char* ID);
	
public:
	char id [256];
	std::fstream* fios;
};


#endif
