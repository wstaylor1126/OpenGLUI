#if !defined(_SGFX_BMP_TEXTURES_H_)
#define _SGFX_BMP_TEXTURES_H_

#include "SGFXEngine.h"

//--Honestly this code is really hacky. I might clean it up later or overhaul it. For now it works as a placeholder

class BMPTextureData
{
public:
	BMPTextureData(const char* path);
	~BMPTextureData();
	void Load();

	char* pixelData;
	unsigned long long pixelDataSize;
	unsigned long dibHeaderSize, imageWidth, imageHeight;
	unsigned short bitsPerPixel;
private:
	const char* filePath;
	unsigned long long diskSize;
	void BMPRedBlueChannelFlip();
};

#endif