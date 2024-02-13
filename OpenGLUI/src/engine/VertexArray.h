#pragma once
#include "SGFXEngine.h"

class VertexArray
{
public:
	VertexArray();
	~VertexArray();
	void Bind();
	void Unbind();
	unsigned int vertexArrayId;
private:
};
