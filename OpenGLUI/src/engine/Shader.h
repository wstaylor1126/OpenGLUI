#pragma once
#include <iostream>
#include <string>
#include <fstream>

#include "UIEngine.h"

inline unsigned int colorLocation;

namespace shader
{
}

class BasicShaderProgram
{
public:

	std::string GetString();
	BasicShaderProgram(const char* vertexFilePath, const char* fragmentFilePath);
	void CreateShaderProgram();
	unsigned int shaderProgramId;
private:
	const char* vertexShaderPath;
	const char* fragmentShaderPath;
	std::string vertexShaderStr;
	std::string fragmentShaderStr;

	unsigned int CompileShader(unsigned int shaderType, std::string& shaderSource);
	void LoadFromDisk(std::string& shaderString, const char* filePath);
};