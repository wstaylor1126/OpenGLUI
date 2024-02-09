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

	BasicShaderProgram shaderProgram("C:\\Users\\Falcon\\source\\repos\\OpenGLUI\\OpenGLUI\\Shaders\\BaseVertex.vert", "C:\\Users\\Falcon\\source\\repos\\OpenGLUI\\OpenGLUI\\Shaders\\BaseFrag.frag");
	shaderProgram.CreateShaderProgram();

	

	glUseProgram(shaderProgram.shaderProgramId);
	colorLocation = glGetUniformLocation(shaderProgram.shaderProgramId, "baseColor");


	glfwSwapInterval(1);


	unsigned int vertexBufId;
	glGenBuffers(1, &vertexBufId);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBufId);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, (const void*)0);

	
	while (1)
	{

		if (glfwWindowShouldClose(ui.window))
		{
			glfwDestroyWindow(ui.window);
			break;
		}

		if (uiengine::cursorIsHeld == 1)
		{
			uiengine::verticies[uiengine::vertexId * 2 - 2] = uiengine::PixelToVertex(ui.cursorPosX, 1280);
			uiengine::verticies[uiengine::vertexId * 2 - 1] = -uiengine::PixelToVertex(ui.cursorPosY, 720);
		}


		glClear(GL_COLOR_BUFFER_BIT);

		glBufferData(GL_ARRAY_BUFFER, 8 * sizeof(float), uiengine::verticies, GL_STATIC_DRAW);

		

		glUniform4f(colorLocation, sin(glfwGetTime()+0.5f)+1.5f, sin(glfwGetTime()+1.5f/2), sin(glfwGetTime()+1/3), 1.0f);

		glDrawArrays(GL_QUADS, 0, 4);

		glfwSwapBuffers(ui.window);
		glfwPollEvents();
	}

	ui.~UIEngine();
	//GLLog.Dump();
	return 0;
}