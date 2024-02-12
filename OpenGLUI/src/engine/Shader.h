#pragma once

#include "SGFXEngine.h"

class Shader
{
public:

	Shader(const char* filePath, unsigned int type);
	~Shader();
	void Init();
	unsigned int shaderId;
	unsigned int shaderType;
private:
	const char* shaderPath;
	std::string shaderStr;

	unsigned int CompileShader(std::string& shaderSource);
	void LoadFromDisk(std::string& shaderString, const char* filePath);
};

class BasicShaderProgram
{
public:

	BasicShaderProgram();
	~BasicShaderProgram() = default;
	void AttachShader(Shader& shader);
	void CompileAndAttachShader(const char* sPath, unsigned int sType);
	void UseProgram();

	unsigned int shaderProgramObjId;
private:
};

namespace shader
{
}

