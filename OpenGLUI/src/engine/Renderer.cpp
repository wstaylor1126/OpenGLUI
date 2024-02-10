#include "Renderer.h"

void Draw(GLFWwindow* window)
{

	glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glBufferData(GL_ARRAY_BUFFER, 30 * sizeof(float), renderer::verticies, GL_STATIC_DRAW);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, 12 * sizeof(unsigned int), renderer::indexBuffer, GL_STATIC_DRAW);

	//glUniform4f(colorLocation, sin(glfwGetTime() + 0.5f) + 1.5f, sin(glfwGetTime() + 1.5f / 2), sin(glfwGetTime() + 1 / 3), 1.0f);

	glDrawElements(GL_TRIANGLES, 12, GL_UNSIGNED_INT, nullptr);

	glfwSwapBuffers(window);
}