#include "Shader.h"

Shader::Shader()
{
}
Shader::Shader(unsigned int type, char* path, char* ID)
{
}
bool Shader::loadFile(unsigned int type, char* path, char* ID)
{
	bool result = File::loadFile(path, ID);

	return result;
}

bool Shader::Compile()
{
	return false;
}

std::vector<char> Shader::getErrors()
{
	int errorLength;
	glGetShaderiv(this->id, GL_COMPILE_STATUS, &this->result);
	glGetShaderiv(this->id, GL_INFO_LOG_LENGTH, &errorLength);
    std::vector<char> errors(errorLength);
    glGetShaderInfoLog(this->id, errorLength, NULL, &errors[0]);
	return errors;
}

bool Shader::Attach()
{
	return false;
}
