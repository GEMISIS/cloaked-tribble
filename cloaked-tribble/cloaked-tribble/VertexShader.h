#ifndef _VERTEX_SHADER_H_
#define _VERTEX_SHADER_H_

#include "File.h"

class VertexShader : public File
{
public:
	VertexShader();
	VertexShader(char* path, char* ID);
};

#endif