#include "BMPTextures.h"

BMPTexture::BMPTexture(const char* path)
{
	filePath = path;
}
BMPTexture::~BMPTexture()
{
	delete[] pixelData;
}
void BMPTexture::Load()
{

	std::ifstream bmpStream(filePath);
	bmpStream.seekg(0, bmpStream.end);
	diskSize = bmpStream.tellg();
	bmpStream.seekg(0, bmpStream.beg);
	//--BMP header is 14 bytes
	char bmpHeader[14];
	bmpStream.read(bmpHeader, 14);
	unsigned long bmpPixelDataStartAddress = *(unsigned long*)(bmpHeader + 10);
	pixelDataSize = diskSize - bmpPixelDataStartAddress;

	bmpStream.read((char*)&dibHeaderSize, 4);

	char* dibHeader = new char[dibHeaderSize - 4];
	bmpStream.read(dibHeader, dibHeaderSize - 4);
	//--Copy over all of the relevant header info.
	imageWidth = *(unsigned long*)dibHeader;
	imageHeight = *(unsigned long*)(dibHeader + 4);
	bitsPerPixel = *(unsigned short*)(dibHeader + 10);

	delete[] dibHeader;

	pixelData = new char[pixelDataSize];
	std::memset(pixelData, '\x00', pixelDataSize);
	bmpStream.seekg(bmpPixelDataStartAddress, bmpStream.beg);
	bmpStream.read(pixelData, pixelDataSize);
	bmpStream.close();
}