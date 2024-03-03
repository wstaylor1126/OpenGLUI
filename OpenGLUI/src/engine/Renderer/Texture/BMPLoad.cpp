#include "BMPLoad.h"

//--Public
BMPTextureData::BMPTextureData(const char* path)
{
	filePath = path;
}
BMPTextureData::~BMPTextureData()
{
	/*This might have to change, for now its just to prevent memory leaks by basically making it a unique_ptr, but a propper resource manager will
	probably require that this is not in place*/
	delete[] pixelData;
}
void BMPTextureData::Load()
{

	std::ifstream bmpStream(filePath, std::ifstream::binary);
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

	int increment = 0;
	while (bmpStream.good())
	{

		bmpStream.read(pixelData + increment, 4096);
		increment += 4096;
	}
	
	bmpStream.close();
	//BMPRedBlueChannelFlip();
}
//--Private
void BMPTextureData::BMPRedBlueChannelFlip() //--This is absolutely evil
{
	for (unsigned long i = 0; i < pixelDataSize; i += 4)
	{
		unsigned long cpy = *(unsigned int*)(pixelData + i);
		unsigned char blueChannel = *(unsigned char*)&cpy;
		unsigned char redChannel = *((unsigned char*)(&cpy) + 2);

		*(unsigned char*)&cpy = redChannel;
		*((unsigned char*)(&cpy) + 2) = blueChannel;

		*(unsigned int*)(pixelData + i) = cpy;
	}
}