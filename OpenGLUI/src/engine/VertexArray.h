#pragma once
#include "SGFXEngine.h"

//--Basic abstrction for the GLVertexArrayObject. SGFXEngine will most likely use just one but this makes it easy to add more if wanted

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
