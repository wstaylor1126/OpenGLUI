#include "VertexArray.h"

VertexArray::VertexArray()
{
	glGenVertexArrays(1, &vertexArrayId);
}
VertexArray::~VertexArray()
{
	glDeleteVertexArrays(1, &vertexArrayId);
};
void VertexArray::Bind() const
{
	glBindVertexArray(vertexArrayId);
}
void VertexArray::Unbind() const
{
	glBindVertexArray(0);
}