#include <windows.h>

#include <iostream>

#include "sLib.h"
#include "SGFXEngine.h"

using namespace std;
using namespace sgfxengine;
using namespace sgfxtypes;
using namespace shader;


int main()
{
	
	//Log GLLog("C:\\Users\\Falcon\\OneDrive\\Desktop\\GLLog.txt", "GLLog");

	SGFXEngine ui;

	if (!ui.Init(1280, 720, "UIEngine"))
	{
		std::cout << "Error initializing UIEngine" << std::endl;
		return 0;
	};
	

	//GLLog.Write("UIEngine successfully initialized");

	BasicShaderProgram shaderProgram;
	shaderProgram.CompileAndAttachShader("C:\\Users\\Falcon\\source\\repos\\OpenGLUI\\OpenGLUI\\Shaders\\BaseVertex.vert", GL_VERTEX_SHADER);
	shaderProgram.CompileAndAttachShader("C:\\Users\\Falcon\\source\\repos\\OpenGLUI\\OpenGLUI\\Shaders\\BaseFrag.frag", GL_FRAGMENT_SHADER);
	shaderProgram.UseProgram();


	textureLocation = glGetUniformLocation(shaderProgram.shaderProgramObjId, "unif_Texture");


	glfwSwapInterval(0);


	unsigned int vertexAttribArrayId;
	glGenVertexArrays(1, &vertexAttribArrayId);
	glBindVertexArray(vertexAttribArrayId);
	

	while (!glfwWindowShouldClose(ui.window))
	{
		//if (sgfxengine::cursorIsHeld == 1)
		//{
		//	renderer::vertexPositions[sgfxengine::vertexId * 4 - 4] = sgfxengine::PixelToVertex(ui._cursorPosX_, ui._windowX_);
		//	renderer::vertexPositions[sgfxengine::vertexId * 4 - 3] = -sgfxengine::PixelToVertex(ui._cursorPosY_, ui._windowY_);
		//	renderer::vertexPositions[16] = sgfxengine::PixelToVertex(ui._cursorPosX_, ui._windowX_);
		//	renderer::vertexPositions[17] = -sgfxengine::PixelToVertex(ui._cursorPosY_, ui._windowY_);
		//}

		Draw(ui.window);

		glfwPollEvents();
	}

	ui.~SGFXEngine();
	//GLLog.Dump();
	return 0;
}
