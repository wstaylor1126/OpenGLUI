#include "Renderer.h"

void Draw(GLFWwindow* window)
{

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);


	
	GLCallErr(glUniform1i(textureLocation, 0));

	GLCallErr(glDrawElements(GL_TRIANGLES, vertexCount, GL_UNSIGNED_INT, nullptr));
}