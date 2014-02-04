#ifndef _FILEMANAGER_H_
#define _FILEMANAGER_H_

#include <vector>
#include "File.h"

class FileManager
{
public:
	FileManager();
	bool Init();
	bool Destroy();
	bool openFile(char* path, char* ID);
	bool closeFile(char* ID);
	File* getFileById(char* ID);
	bool trim();

protected:
	std::vector<File*> fileStreams;

};



#endif