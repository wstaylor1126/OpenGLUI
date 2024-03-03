#include "Shader.h"

//--Public

BasicShaderProgram::BasicShaderProgram()
{
	shaderProgramObjId = glCreateProgram();
}
void BasicShaderProgram::UseProgram()
{
	glLinkProgram(shaderProgramObjId);
	glValidateProgram(shaderProgramObjId);
	//--Probably some error handling to do. I mean there's a lot to do everywhere but it'll be later

	glUseProgram(shaderProgramObjId);
}
void BasicShaderProgram::AttachShader(ShaderSource& shader)
{
	glAttachShader(shaderProgramObjId, shader.shaderObjId);
}
void BasicShaderProgram::CompileAndAttachShader(const char* sPath, unsigned int sType)
{
	ShaderSource newShader(sPath, sType);
	newShader.LoadAndCompile();
	AttachShader(newShader);

	newShader.~ShaderSource();
}

//--Public

void ShaderSource::LoadAndCompile()
{
	LoadFromDisk(shaderFilePath);
	shaderObjId = CompileShader(shaderStr);
}
ShaderSource::ShaderSource(const char* filePath, unsigned int type)
	: shaderFilePath(filePath), shaderType(type)
{}

//--Private

unsigned int ShaderSource::CompileShader(const std::string& shaderSource)
{
	unsigned int shaderId = glCreateShader(shaderType);
	const char* sourceCStr = shaderSource.c_str();
	glShaderSource(shaderId, 1, &sourceCStr, nullptr);
	glCompileShader(shaderId);

	int no_err;
	glGetShaderiv(shaderId, GL_COMPILE_STATUS, &no_err);
	if (!no_err)
	{
		int strLen;
		glGetShaderiv(shaderId, GL_INFO_LOG_LENGTH, &strLen);
		char* msg = new char[strLen];

		std::memset(msg, '\x00', strLen);
		glGetShaderInfoLog(shaderId, strLen, &strLen, msg);
		
		std::cout << "(" << std::hex << shaderType << std::dec << ")" << "Failed to compile shader:\n" << msg << std::endl;

		delete[] msg;
	}

	return shaderId;
}
void ShaderSource::LoadFromDisk(const char* filePath)
{
	int sizeOnDisk;
	char shaderBytes[_MAX_BASIC_SHADER_SIZE_];

	std::memset(shaderBytes, '\x00', _MAX_BASIC_SHADER_SIZE_);
	std::ifstream readStream(filePath, std::ifstream::binary);
	readStream.seekg(0, readStream.end);
	sizeOnDisk = readStream.tellg();

	if (sizeOnDisk > _MAX_BASIC_SHADER_SIZE_)
	{
#if defined(_BASIC_SHADER_DEBUG_)
		std::cout << "Basic shader size on disk exceeds the size of " << _MAX_BASIC_SHADER_SIZE_ << std::endl;
#endif
		return;
	}
	//-- Reset pointer to beginning
	readStream.seekg(0, readStream.beg);

	readStream.read(shaderBytes, sizeOnDisk);

	shaderStr = std::string(shaderBytes, sizeOnDisk);
	return;
}
ShaderSource::~ShaderSource()
{
	glDeleteShader(shaderObjId);
}