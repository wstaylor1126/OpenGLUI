#include "Renderer.h"


void Draw(GLFWwindow* window)
{
	//float scalar = (sin(glfwGetTime())) + 2.0f;

	//renderer::vertexColors[16] = sin(glfwGetTime());
	//renderer::vertexPositions[3] = scalar;
	//renderer::vertexPositions[7] = scalar;
	//renderer::vertexPositions[11] = scalar;
	//renderer::vertexPositions[15] = scalar;
	//renderer::vertexPositions[19] = scalar;

	//std::cout << 0.25f/scalar << std::endl;


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

	BMPTexture texture("C:\\Users\\Falcon\\OneDrive\\Desktop\\texture.bmp");
	texture.Load();

	unsigned int indexBufId;
	unsigned int vertexPosBufId;
	unsigned int textureCoordinateId;

	unsigned int textureId;

	glGenBuffers(1, &indexBufId);
	glGenBuffers(1, &vertexPosBufId);
	glGenBuffers(1, &textureCoordinateId);
	glGenTextures(1, &textureId);

	glBindBuffer(GL_ARRAY_BUFFER, vertexPosBufId);

	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 4, (const void*)0);
	glBufferData(GL_ARRAY_BUFFER, 24 * sizeof(float), renderer::textureData, GL_STATIC_DRAW);

	glBindBuffer(GL_ARRAY_BUFFER, textureCoordinateId);

	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(float) * 4, (const void*)2);
	glBufferData(GL_ARRAY_BUFFER, 24 * sizeof(float), renderer::textureData, GL_STATIC_DRAW);


	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufId);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * sizeof(unsigned int), renderer::indexBuffer, GL_STATIC_DRAW);

	glBindTexture(GL_TEXTURE_2D, textureId);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, texture.imageWidth, texture.imageHeight, 0, GL_RGBA, GL_BYTE, texture.pixelData);
	
	glUniform1i(textureLocation, 0);

	
	//glDrawElements(GL_TRIANGLES, vertexCount, GL_UNSIGNED_INT, nullptr);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);

	glfwSwapBuffers(window);

	//glDeleteBuffers(1, &indexBufId);
	//glDeleteBuffers(1, &vertexPosBufId);
	//glDeleteBuffers(1, &vertexColorBufId);

	glDeleteBuffers(1, &indexBufId);
	glDeleteBuffers(1, &vertexPosBufId);

	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
}