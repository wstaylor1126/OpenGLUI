#pragma once
#include "SGFXEngine.h"


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
};
