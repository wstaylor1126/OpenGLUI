#include "Renderer.h"

void Draw(GLFWwindow* window)
{
	float scalar = (sin(glfwGetTime())) + 2.0f;

	renderer::vertexPositions[3] = scalar;
	renderer::vertexPositions[7] = scalar;
	renderer::vertexPositions[11] = scalar;
	renderer::vertexPositions[15] = scalar;

	//std::cout << 0.25f/scalar << std::endl;

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);




	glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);


	//unsigned int indexBufId;
	//unsigned int vertexPosBufId;
	//unsigned int vertexColorBufId;
	//glGenBuffers(1, &indexBufId);
	//glGenBuffers(1, &vertexPosBufId);
	//glGenBuffers(1, &vertexColorBufId);

	//glBindBuffer(GL_ARRAY_BUFFER, vertexPosBufId);

	//glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(float) * 4, (const void*)0);
	//glBufferData(GL_ARRAY_BUFFER, 4*vertexAttribCount * sizeof(float), renderer::vertexPositions, GL_STATIC_DRAW);

	//glBindBuffer(GL_ARRAY_BUFFER, vertexColorBufId);

	//glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(float) * 4, (const void*)(sizeof(float) * 0));
	//glBufferData(GL_ARRAY_BUFFER, 4 * vertexAttribCount * sizeof(float), renderer::vertexColors, GL_STATIC_DRAW);

	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufId);
	//glBufferData(GL_ELEMENT_ARRAY_BUFFER, vertexCount * sizeof(unsigned int), renderer::indexBuffer, GL_STATIC_DRAW);

	unsigned int indexBufId;
	unsigned int vertexPosBufId;
	unsigned int textureCoordinateId;

	//glGenBuffers(1, &indexBufId);
	//glGenBuffers(1, &vertexPosBufId);
	//glGenBuffers(1, &textureCoordinateId);

	static int runOnce = 0;
	if (runOnce == 0)
	{
		glGenBuffers(1, &indexBufId);
		glGenBuffers(1, &vertexPosBufId);
		glGenBuffers(1, &textureCoordinateId);

		runOnce = 1;
		glBindBuffer(GL_ARRAY_BUFFER, vertexPosBufId);
		glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(float) * 4, (const void*)0);

		glBindBuffer(GL_ARRAY_BUFFER, textureCoordinateId);
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, (const void*)0);
	}

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufId);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * sizeof(unsigned int), renderer::indexBuffer, GL_STATIC_DRAW);


	glBindBuffer(GL_ARRAY_BUFFER, vertexPosBufId);
	glBufferData(GL_ARRAY_BUFFER, 16 * sizeof(float), renderer::vertexPositions, GL_STATIC_DRAW);
	//glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(float) * 4, (const void*)0);


	glBindBuffer(GL_ARRAY_BUFFER, textureCoordinateId);
	glBufferData(GL_ARRAY_BUFFER, 8 * sizeof(float), renderer::textureCoords, GL_STATIC_DRAW);
	//glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, (const void*)0);


	glUniform1i(textureLocation, 0);

	//glDrawElements(GL_TRIANGLES, vertexCount, GL_UNSIGNED_INT, nullptr);

	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);

	glfwSwapBuffers(window);

	//glDeleteBuffers(1, &indexBufId);
	//glDeleteBuffers(1, &vertexPosBufId);
	//glDeleteBuffers(1, &vertexColorBufId);

	//glDeleteBuffers(1, &indexBufId);
	//glDeleteBuffers(1, &vertexPosBufId);
	//glDeleteBuffers(1, &textureCoordinateId);

	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
}