#include <windows.h>

#include <iostream>

#include "sLib.h"
#include "UIEngine.h"

using namespace std;


int main()
{
	//Log GLLog("C:\\Users\\Falcon\\OneDrive\\Desktop\\GLLog.txt", "GLLog");


	UIEngine ui;

	if (!ui.Init(1280, 720, "UIEngine"))
	{
		std::cout << "Error initializing UIEngine" << std::endl;
		return 0;
	};


	//GLLog.Write("UIEngine successfully initialized");

	BasicShaderProgram shaderProgram;
	shaderProgram.CreateAndAttachShader("C:\\Users\\Falcon\\source\\repos\\OpenGLUI\\OpenGLUI\\Shaders\\BaseVertex.vert", GL_VERTEX_SHADER);
	shaderProgram.CreateAndAttachShader("C:\\Users\\Falcon\\source\\repos\\OpenGLUI\\OpenGLUI\\Shaders\\BaseFrag.frag", GL_FRAGMENT_SHADER);
	shaderProgram.UseProgram();


	colorLocation = glGetUniformLocation(shaderProgram.shaderProgramObjId, "color");


	glfwSwapInterval(0);


	unsigned int vertexBufId;
	glGenBuffers(1, &vertexBufId);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBufId);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 6, (const void*)0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(float) * 6, (const void*)8);
	

	unsigned int indexBufId;
	glGenBuffers(1, &indexBufId);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufId);
	

	while (!glfwWindowShouldClose(ui.window))
	{
		if (uiengine::cursorIsHeld == 1)
		{
			renderer::verticies[uiengine::vertexId * 6 - 6] = uiengine::PixelToVertex(ui._cursorPosX_, ui._windowX_);
			renderer::verticies[uiengine::vertexId * 6 - 5] = -uiengine::PixelToVertex(ui._cursorPosY_, ui._windowY_);
			renderer::verticies[24] = uiengine::PixelToVertex(ui._cursorPosX_, ui._windowX_);
			renderer::verticies[25] = -uiengine::PixelToVertex(ui._cursorPosY_, ui._windowY_);
		}

		Draw(ui.window);

		glfwPollEvents();
	}

	ui.~UIEngine();
	//GLLog.Dump();
	return 0;
}