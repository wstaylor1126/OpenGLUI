#include <windows.h>

#define GLEW_STATIC

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>

#include "sLib.h"

using namespace std;

BasicShaderFile randShader("C:\\Users\\Falcon\\OneDrive\\Desktop\\slib.txt");


int main()
{
	Log GLLog("C:\\Users\\Falcon\\OneDrive\\Desktop\\GLLog.txt", "GLLog");



	randShader.Load();

	if (!glfwInit())
	{

		std::cout << "GLFW initialization failed." << std::endl;

		return 0;
	}

	GLLog.Write("GLFW initialization successful.");
	
	GLFWwindow* window = glfwCreateWindow(1280, 720, "GL_4.6", nullptr, nullptr);
	glfwMakeContextCurrent(window);

	GLenum errCode = glewInit();

	if (errCode)
	{
		const char* glewErrStr = (char*)glewGetErrorString(errCode);
		GLLog.Write(std::string(glewErrStr));
		std::cout << "GLEW error: " << glewErrStr << std::endl;
	}


	glfwSwapInterval(1);
	
	float random = 0.0f;

//--Quad 1

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

		random += 0.025f;
		float randSin = sin(random);


		if (glfwWindowShouldClose(window))
		{
			glfwDestroyWindow(window);
			break;
		}
		
		glClear(GL_COLOR_BUFFER_BIT);
		
		*(float*)((char*)Quad1Vertices + sizeof(float)) = randSin;
		*(float*)((char*)Quad1Vertices) = randSin;
		glBufferData(GL_ARRAY_BUFFER, 8 * sizeof(float), Quad1Vertices, GL_STATIC_DRAW);

		glDrawArrays(GL_QUADS, 0, 4);

		glBegin(GL_TRIANGLES);
		glColor3f(randSin, 0.4f, 0.5f);
		glVertex2f(Quad1Vertices[0], Quad1Vertices[1]);
		glVertex2f(Quad1Vertices[2], Quad1Vertices[3]);
		glVertex2f(Quad1Vertices[4], Quad1Vertices[5]);
		glEnd();


		

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();

	GLLog.Dump();
	return 0;
}