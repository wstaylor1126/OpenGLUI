#if !defined(_SGFX_VERTEX_BUFFER_H_)
#define _SGFX_VERTEX_BUFFER_H_

#include "SGFXEngine.h"

class VertexBuf
{
public:
	VertexBuf(void* vertexData, unsigned int bufSize);
	~VertexBuf();
	void Bind() const;
	void Unbind() const;
	void* GetVertexData() const;
	void ReloadVertexData(void* vertexData, unsigned int bufSize);
	void DeleteGLBuf();

	unsigned int vertexBufId, size;
private:
	void* vData;
};

class VertexAttribBufLayout
{
public:
	std::vector<VertexBuf> layout;

	VertexAttribBufLayout();
	~VertexAttribBufLayout();
	void PushNewAttribute(VertexBuf vBuf, unsigned int glType, unsigned int attribLength, unsigned int attribElementSize, unsigned int offset=0);
	void ClearAttributes();
private:
};

#endif
