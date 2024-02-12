#pragma once
#include "SGFXEngine.h"


class BMPTexture
{
public:
	BMPTexture(const char* path);
	~BMPTexture();
	void Load();

	char* pixelData;
	unsigned long long pixelDataSize;
	unsigned long dibHeaderSize, imageWidth, imageHeight;
	unsigned short bitsPerPixel;
private:
	const char* filePath;
	unsigned long long diskSize;
};
