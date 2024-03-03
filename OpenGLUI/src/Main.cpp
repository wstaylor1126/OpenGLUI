#include <windows.h>

#include <iostream>


#include "sLib.h"
#include "SGFXEngine.h"

using namespace std;
using namespace sgfxengine;

int main()
{
	
	Log GLLog("C:\\Users\\Falcon\\OneDrive\\Desktop\\GLLog.bin", "GLLog");

	SGFXEngine ui;

	if (!ui.Init(1440, 810, "UIEngine"))
	{
		std::cout << "Error initializing UIEngine" << std::endl;
		return 0;
	};

	GLLog.Write("UIEngine successfully initialized");

	BMPTextureData texture("C:\\Users\\Falcon\\OneDrive\\Desktop\\texture.bmp");
	texture.Load();

	unsigned int textureId;
	glActiveTexture(GL_TEXTURE0);

	glGenTextures(1, &textureId);
	glBindTexture(GL_TEXTURE_2D, textureId);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, texture.imageWidth, texture.imageHeight, 0, GL_BGRA, GL_UNSIGNED_BYTE, texture.pixelData);

	BasicShaderProgram shaderProgram;
	shaderProgram.CompileAndAttachShader("C:\\Users\\Falcon\\source\\repos\\OpenGLUI\\OpenGLUI\\Shaders\\BaseVertex.vert", GL_VERTEX_SHADER);
	shaderProgram.CompileAndAttachShader("C:\\Users\\Falcon\\source\\repos\\OpenGLUI\\OpenGLUI\\Shaders\\BaseFrag.frag", GL_FRAGMENT_SHADER);
	shaderProgram.UseProgram();

	textureLocation = glGetUniformLocation(shaderProgram.shaderProgramObjId, "unif_Texture");


	glfwSwapInterval(0);

	VertexArray mainVertexArray;
	mainVertexArray.Bind();

	VertexAttribBufLayout vertLayout;

	IndexBuf indicies(renderer::indexBuffer, vertexCount);
	VertexBuf vertexPosAttrib(renderer::vertexPositions, vertexAttribCount * 4 * sizeof(float));
	VertexBuf vertexTextCoordAttrib(renderer::textureCoords, vertexAttribCount * 2 * sizeof(float));
	vertLayout.PushNewAttribute(vertexPosAttrib, GL_FLOAT, 4, sizeof(float));
	vertLayout.PushNewAttribute(vertexTextCoordAttrib, GL_FLOAT, 2, sizeof(float));

	while (!glfwWindowShouldClose(ui.window))
	{
		float scalar = (sin(glfwGetTime())) + 1.5f;

		renderer::vertexPositions[3] = scalar;
		renderer::vertexPositions[11] = -scalar + 2.0f;
		renderer::textureCoords[0] = -scalar;
		renderer::textureCoords[1] = scalar;
		if (sgfxengine::cursorIsHeld == 1)
		{
			renderer::vertexPositions[sgfxengine::vertexId * 4 - 4] = sgfxengine::PixelToVertex(ui._cursorPosX_, ui._windowX_);
			renderer::vertexPositions[sgfxengine::vertexId * 4 - 3] = -sgfxengine::PixelToVertex(ui._cursorPosY_, ui._windowY_);
		}

		vertexPosAttrib.ReloadVertexData(renderer::vertexPositions, vertexAttribCount * 4 * sizeof(float));
		vertexTextCoordAttrib.ReloadVertexData(renderer::textureCoords, vertexAttribCount * 2 * sizeof(float));


		Draw(ui.window);

		glfwSwapBuffers(ui.window);

		glfwPollEvents();
	//	vertLayout.ClearAttributes();
	}
	
	glDeleteTextures(1, &textureId);
	ui.~SGFXEngine();
	GLLog.Dump();
	return 1;
}
