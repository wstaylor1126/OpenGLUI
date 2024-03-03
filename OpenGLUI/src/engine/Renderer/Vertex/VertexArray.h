#if !defined(_SGFX_VERTEX_ARRAY_H_)
#define _SGFX_VERTEX_ARRAY_H_

#include "SGFXEngine.h"

//--Basic abstraction for the GLVertexArrayObject. SGFXEngine will most likely use just one but this makes it easy to add more if wanted

class VertexArray
{
public:
	VertexArray();
	~VertexArray();
	void Bind() const;
	void Unbind() const;
	unsigned int vertexArrayId;
private:
};

#endif
