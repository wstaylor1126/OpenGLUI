#pragma once
#include <iostream>
#include <string>
#include <fstream>

#include "UIEngine.h"

class BasicShaderFile
{
public:
	void Load();
	std::string GetString();
	BasicShaderFile(const char* filePath);
private:
	const char* filePathI;
	char shaderBytes[_MAX_BASIC_SHADER_SIZE_]; //--Yeah it's gonna be on the stack. Hopefully gets passed to rendering api fast
	int sizeOnDisk;
};