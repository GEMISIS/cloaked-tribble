#ifndef _VERTEX_SHADER_H_
#define _VERTEX_SHADER_H_

#include <GL/glew.h>
#include <vector>
#include <string>
#include <iostream>
#include "File.h"

class Shader
{
public:
	Shader();
	Shader(unsigned int type, char* path, char* ID);
	bool loadFile(unsigned int type, char* path, char* ID);

	bool Compile();
	const char* getErrors();
	bool Attach(unsigned int programID);
	bool Cleanup();
protected:
	unsigned int id;
	std::string source;
	int result;
};


#endif

