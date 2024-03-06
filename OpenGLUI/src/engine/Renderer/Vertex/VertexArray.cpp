#include "VertexArray.h"

VertexArray::VertexArray()
{
	GLCallErr(glGenVertexArrays(1, &vertexArrayId));
}
VertexArray::~VertexArray()
{
	GLCallErr(glDeleteVertexArrays(1, &vertexArrayId));
};
void VertexArray::Bind() const
{
	GLCallErr(glBindVertexArray(vertexArrayId));
}
void VertexArray::Unbind() const
{
	GLCallErr(glBindVertexArray(0));
}