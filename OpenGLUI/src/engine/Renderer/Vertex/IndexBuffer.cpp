#include "IndexBuffer.h"

IndexBuf::IndexBuf(const void* indexData, unsigned int count)
	: amount(count)
{
	GLCallErr(glGenBuffers(1, &indexBufId));
	GLCallErr(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufId));
	GLCallErr(glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), indexData, GL_STATIC_DRAW));
}
IndexBuf::~IndexBuf() = default;

void IndexBuf::DeleteGLBuf()
{
	GLCallErr(glDeleteBuffers(1, &indexBufId));
	IndexBuf::~IndexBuf();
}

void IndexBuf::Bind() const
{
	GLCallErr(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufId));
}
void IndexBuf::Unbind() const
{
	GLCallErr(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
}