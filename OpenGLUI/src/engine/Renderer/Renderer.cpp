#include "Renderer.h"

void sgfxDraw(const ShaderProgram& shader, const VertexArray& vertexArray, const IndexBuf& indexBuffer, const VertexAttribBufLayout& vertexAttributes)
{
	vertexArray.Bind();
	shader.UseProgram();
	indexBuffer.Bind();




	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);


	GLCallErr(glDrawElements(GL_TRIANGLES, vertexCount, GL_UNSIGNED_INT, nullptr));


	indexBuffer.Unbind();
	shader.UnloadProgram();
	vertexArray.Unbind();
}