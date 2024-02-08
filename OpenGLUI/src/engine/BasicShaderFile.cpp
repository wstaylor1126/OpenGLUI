#include "BasicShaderFile.h"

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