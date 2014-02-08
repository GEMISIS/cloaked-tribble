#include "Shader.h"

Shader::Shader()
{
}
Shader::Shader(unsigned int type, char* path, char* ID)
{
	this->loadFile(type, path, ID);
}
bool Shader::loadFile(unsigned int type, char* path, char* ID)
{
	std::ifstream fios(path, std::fstream::in);

	if(fios.is_open())
	{
		this->id = glCreateShader(type);

		std::string code = "";

		while(getline(fios, code))
		{
			this->source += code;
			this->source += "\n";
		}

		fios.close();

		return true;
	}

	return false;
}

bool Shader::Compile()
{
	char* codeCopy =  new char[this->source.length() + 1];
	std::strcpy(codeCopy, this->source.c_str());
	const char* code = codeCopy;
	glShaderSource(this->id, 1, &code, NULL);
	glCompileShader(this->id);
	return true;
}

const char* Shader::getErrors()
{
	int errorLength;
	this->result = 0;
	glGetShaderiv(this->id, GL_COMPILE_STATUS, &this->result);
	glGetShaderiv(this->id, GL_INFO_LOG_LENGTH, &errorLength);
	char* errors = new char[errorLength];
    glGetShaderInfoLog(this->id, errorLength, NULL, errors);
	return errors;
}

bool Shader::Attach(unsigned int programID)
{
	glAttachShader(programID, this->id);
	return true;
}

bool Shader::Cleanup()
{
	glDeleteShader(this->id);
	return true;
}
