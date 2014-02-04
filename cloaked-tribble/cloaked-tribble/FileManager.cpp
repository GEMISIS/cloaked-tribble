#include "FileManager.h"
#include <vector>
#include <cstring>
#ifdef _DEBUG
#include <iostream>
#endif
#include "File.h"

FileManager::FileManager(){
}
bool FileManager::Init()
{
	return true;
}
bool FileManager::Destroy()
{

	for(std::vector<File*>::iterator it=fileStreams.end();;){
		File* f = *it;
		f->fios->close();
		fileStreams.clear();

	}

	return false;
}
bool FileManager::openFile(char* path, char* ID)
{
	File placeholder(path, ID);
	//check that the file works

	if(placeholder.fios->is_open()){
		fileStreams.push_back(&placeholder);
	} else {
		//file won't open D: le gasp
#ifdef _DEBUG
		std::cout<<"File "<<path<<" will not open!"<<std::endl;
#endif
		return false;
	}


	return true;
}
bool FileManager::closeFile(char* ID)
{

	//find file
	getFileById(ID)->fios->close();


	return true;

}
File* FileManager::getFileById(char* ID)
{
	for(std::vector<File*>::iterator it=fileStreams.begin();it!=fileStreams.end();++it){
		File* tmp = *it;
		if(std::strcmp(tmp->id,ID)==0)
			return tmp;
	}
#ifdef _DEBUG
	std::cout<<"Could not find file by ID: "<<ID<<std::endl;
#endif
	return 0;
}
bool FileManager::trim()
{
	for(std::vector<File*>::iterator it=fileStreams.begin();it!=fileStreams.end();++it){
		File* tmp = *it;
		if(!tmp->fios->is_open()){
			//this file isn't open, try to remove it.
			fileStreams.erase(it);
		}
	}
	return true;
}