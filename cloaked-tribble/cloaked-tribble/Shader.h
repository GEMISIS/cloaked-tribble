#ifndef _VERTEX_SHADER_H_
#define _VERTEX_SHADER_H_

#include <GL/glew.h>
#include <vector>
#include "File.h"

class Shader : public File
{
public:
	Shader();
	Shader(unsigned int type, char* path, char* ID);
	bool loadFile(unsigned int type, char* path, char* ID);

	bool Compile();
	std::vector<char> getErrors();
	bool Attach();
protected:
	unsigned int id;
	int result;
};

#endif

