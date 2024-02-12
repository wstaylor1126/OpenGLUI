#pragma once

#include "SGFXEngine.h"

constexpr unsigned int vertexCount = 12;
constexpr unsigned int vertexAttribCount = 5;
inline unsigned int textureLocation;

namespace renderer
{

	
	//inline unsigned int indexBuffer[vertexCount] =
	//{
	//	0, 1, 4,
	//	1, 2, 4,
	//	2, 3, 4,
	//	3, 0, 4,
	//};
	//inline float vertexPositions[vertexAttribCount * 4] =
	//{
	//	0.25f, 0.25f, 0.0f, 1.0f,
	//	0.75f, 0.25f, 0.0f, 1.0f,
	//	0.75f, 0.75f, 0.0f, 1.0f,
	//	0.25f, 0.75f, 0.0f, 1.0f,
	//	0.5f, 0.5f, 0.0f, 1.0f,
	//};
	//inline float vertexColors[vertexAttribCount*4] =
	//{
	//	0.0f, 0.2f, 0.5f, 1.0f,
	//	0.5f, 0.5f, 0.1f, 1.0f,
	//	0.7f, 0.5f, 0.8f, 1.0f,
	//	0.5f, 0.5f, 0.1f, 1.0f,
	//	0.8f, 0.1f, 0.5f, 1.0f,
	//};
	inline unsigned int indexBuffer[6] =
	{
		0, 1, 3,
		1, 2, 3,
	};
	inline float textureData[24] =
	{
		0.25f, 0.25f, 1.0f, 1.0f,
		0.75f, 0.25f, 1.0f, 1.0f, 
		0.75f, 0.75f, 1.0f, 1.0f, 
		0.25f, 0.75f, 1.0f, 1.0f,
	};

}

void Draw(GLFWwindow* window);

