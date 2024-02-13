#pragma once

#include "SGFXEngine.h"

constexpr unsigned int vertexCount = 6;
constexpr unsigned int vertexAttribCount = 5;
inline unsigned int textureLocation;

namespace renderer
{
	inline unsigned int indexBuffer[vertexCount] =
	{
		0, 1, 3,
		1, 2, 3,
	};
	inline float vertexPositions[vertexAttribCount * 4] =
	{
		-0.5f, -0.5f, 0.0f, 1.0f,
		0.5f, -0.5f, 0.0f, 1.0f,
		0.5f, 0.5f, 0.0f, 1.0f,
		-0.5f, 0.5f, 0.0f, 1.0f,
	};
	inline float textureCoords[vertexAttribCount * 2] =
	{
		0.0f, 0.0f,
		1.0f, 0.0f,
		1.0f, 1.0f,
		0.0f, 1.0f,
	};
}

void Draw(GLFWwindow* window);

