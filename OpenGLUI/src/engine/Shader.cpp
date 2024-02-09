#include "Shader.h"



unsigned int shader::NewShader(std::string& vShader, std::string& fShader)
{
	unsigned int programId = glCreateProgram();
	unsigned int vertexShaderId = CompileShader(GL_VERTEX_SHADER, vShader);
	unsigned int fragmentShaderId = CompileShader(GL_FRAGMENT_SHADER, fShader);

	glAttachShader(programId, vertexShaderId);
	glAttachShader(programId, fragmentShaderId);
	glLinkProgram(programId);
	glValidateProgram(programId);

	//--Cleanup

	glDeleteShader(vertexShaderId);
	glDeleteShader(fragmentShaderId);
	return programId;
}

unsigned int shader::CompileShader(unsigned int shaderType, std::string& shaderSource)
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


void BasicShaderFile::Load()
{
	std::memset(shaderBytes, '\x00', _MAX_BASIC_SHADER_SIZE_);
	std::ifstream readStream(filePathI);
	readStream.seekg(0, readStream.end);
	sizeOnDisk = readStream.tellg();

	if (sizeOnDisk > _MAX_BASIC_SHADER_SIZE_)
	{
#ifdef _BASIC_SHADER_DEBUG_

		std::cout << "Basic shader size on disk exceeds the size of " << _MAX_BASIC_SHADER_SIZE_ << std::endl;
#endif
		return;
	}
	//-- Reset pointer to beginning
	readStream.seekg(0, readStream.beg);

	readStream.read(shaderBytes, sizeOnDisk);
	return;
}
std::string BasicShaderFile::GetString()
{
	return std::string(shaderBytes, sizeOnDisk);
}
BasicShaderFile::BasicShaderFile(const char* filePath)
{

	filePathI = filePath;
}