#include "VertexBuffer.h"
//--VertexBuf
VertexBuf::VertexBuf(void* vertexData, unsigned int bufSize)
	: size(bufSize)
{
	GLCallErr(glGenBuffers(1, &vertexBufId));
	ReloadVertexData(vertexData, bufSize);
}
VertexBuf::~VertexBuf() = default;

void VertexBuf::Bind() const
{
	GLCallErrDEBUG(glBindBuffer(GL_ARRAY_BUFFER, vertexBufId), vertexBufId);
}
void VertexBuf::Unbind() const
{
	GLCallErr(glBindBuffer(GL_ARRAY_BUFFER, 0));
}
void* VertexBuf::GetVertexData() const
{
	return vData;
}
void VertexBuf::ReloadVertexData(void* vertexData, unsigned int bufSize)
{
	vData = vertexData;
	Bind();
	GLCallErr(glBufferData(GL_ARRAY_BUFFER, bufSize, vertexData, GL_STATIC_DRAW));
}
void VertexBuf::DeleteGLBuf()
{
	GLCallErr(glDeleteBuffers(1, &vertexBufId));
	VertexBuf::~VertexBuf();
}


//--VertexAttribBufLayout

VertexAttribBufLayout::VertexAttribBufLayout() = default;
VertexAttribBufLayout::~VertexAttribBufLayout()
{
	ClearAttributes();
}
void VertexAttribBufLayout::PushNewAttribute(VertexBuf vBuf, unsigned int glType, unsigned int attribLength, unsigned int attribElementSize, unsigned int offset)
{
	layout.push_back(vBuf);

	int index = layout.size() - 1;

	GLCallErrDEBUG(glEnableVertexAttribArray(index), 36);
	vBuf.Bind();
	GLCallErrDEBUG(glVertexAttribPointer(index, attribLength, glType, GL_FALSE, attribElementSize * attribLength, (const void*)offset), 38);
	vBuf.Unbind();
}
void VertexAttribBufLayout::ClearAttributes()
{
	for (int i = 0; i < layout.size(); i++)
	{
		GLCallErrDEBUG(glDisableVertexAttribArray(i), 45);
	}
	layout.clear();
}