#include "File.h"
#include <cstring>
#ifdef _DEBUG
#include <iostream>
#endif
File::File()
{
}
File::File(char* path, char* ID)
{
	//This may be replaced with a load file call in the future depending on the need.
	std::strcpy(id,ID);
	std::fstream tmp(path, std::fstream::in|std::fstream::out);
	if(tmp.is_open()){
		fios = &tmp;
	} else {
		//file couldn't open, leave fios
#ifdef _DEBUG
		std::cout<<"Could not open file "<<path<<std::endl;

#endif
	}
}
bool File::loadFile(char* path, char* ID)
{
	std::strcpy(id,ID);
	std::fstream tmp(path, std::fstream::in|std::fstream::out);
	if(tmp.is_open()){
		fios = &tmp;
	} else {
#ifdef _DEBUG
		std::cout<<"Could not open file "<<path<<std::endl;
#endif
		return false;
	}

	return true;
}
