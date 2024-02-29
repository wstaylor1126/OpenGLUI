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


	while (!glfwWindowShouldClose(ui.window))
	{
		if (sgfxengine::cursorIsHeld == 1)
		{
			renderer::vertexPositions[sgfxengine::vertexId * 4 - 4] = sgfxengine::PixelToVertex(ui._cursorPosX_, ui._windowX_);
			renderer::vertexPositions[sgfxengine::vertexId * 4 - 3] = -sgfxengine::PixelToVertex(ui._cursorPosY_, ui._windowY_);
		}

		Draw(ui.window);

		glfwPollEvents();
	}
	
	glDeleteTextures(1, &textureId);
	ui.~SGFXEngine();
	GLLog.Dump();
	return 0;
}
