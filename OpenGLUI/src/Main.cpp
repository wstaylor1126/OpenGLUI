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

	std::string shaderV = "Penis";
	std::string shaderF = "Dick";
	shader::NewShader(shaderV, shaderF);

	glfwSwapInterval(1);


	float Quad1Vertices[8] =
	{
		-0.5f, -0.5f,
		0.5f, -0.5f,
		0.5f, 0.5f,
		-0.5f, 0.5f
	};

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

		glBufferData(GL_ARRAY_BUFFER, 8 * sizeof(float), Quad1Vertices, GL_STATIC_DRAW);
		glDrawArrays(GL_QUADS, 0, 4);


		//glBegin(GL_QUADS);
		//
		//glColor3f(0.5f, 0.4f, 0.5f);

		////std::cout << ui.vertexW << ui.vertexH << std::endl;

		//glVertex2f(uiengine::verticies[0], uiengine::verticies[1]);
		//glVertex2f(uiengine::verticies[2], uiengine::verticies[3]);
		//glVertex2f(uiengine::verticies[4], uiengine::verticies[5]);
		//glVertex2f(uiengine::verticies[6], uiengine::verticies[7]);
		//glEnd();

		glfwSwapBuffers(ui.window);
		glfwPollEvents();
	}

	ui.~UIEngine();
	//GLLog.Dump();
	return 0;
}