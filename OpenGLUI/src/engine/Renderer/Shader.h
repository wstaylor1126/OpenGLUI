#include "SGFXEngine.h"

#if !defined(_SGFX_SHADER_H_)
#define _SGFX_SHADER_H_

//--This shader loader is going to be expanded upon and improved. It's a little rushed and needs to be cleaned up
//--It's a good foundation though

class ShaderSource
{
public:

	ShaderSource(const char* filePath, unsigned int type);
	~ShaderSource();
	void LoadAndCompile();
	unsigned int shaderObjId, shaderType;
private:
	const char* shaderFilePath;
	std::string shaderStr;

	unsigned int CompileShader(const std::string& shaderSource);
	void LoadFromDisk(const char* filePath);
};

class ShaderProgram
{
public:

	ShaderProgram();
	~ShaderProgram() = default;
	void AttachShader(const ShaderSource& shader) const;
	void CompileAndAttachShader(const char* sPath, unsigned int sType);
	void UseProgram() const;
	void UnloadProgram() const;

	unsigned int shaderProgramObjId;
private:
};

#endif