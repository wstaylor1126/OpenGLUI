#pragma once
#include <iostream>
#include <vector>

#include "UIEngine.h"

namespace renderer
{
	inline unsigned int indexBuffer[12] =
	{
		0, 1, 4,
		1, 2, 4,
		2, 3, 4,
		3, 0, 4,
	};
	inline float verticies[30] =
	{
		-0.5f, -0.5f,/**/0.8f, 0.1f, 0.5f, 1.0f,
		0.5f, -0.5f,/**/0.5f, 0.5f, 0.1f, 1.0f,
		0.5f, 0.5f,/**/0.7f, 0.5f, 0.1f, 1.0f,
		-0.5f, 0.5f,/**/0.5f, 0.5f, 0.1f, 1.0f,
		0.0f, 0.0f,/**/0.0f, 1.0f, 0.8f, 1.0f,
	};
}

void Draw(GLFWwindow* window);