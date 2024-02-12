#pragma once
#define GLEW_STATIC

#define _GL_MAJOR_VERSION_ 3
#define _GL_MINOR_VERSION_ 3

//#define _SUI_NO_DEBUG_

#ifndef _SUI_NO_DEBUG_
#define _SHOW_GL_CONTEXT_INFO_
#define _BASIC_SHADER_DEBUG_
#endif

#define _MAX_BASIC_SHADER_SIZE_ 8192


#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>
#include <fstream>
#include <cmath>

#include "sLib.h"
#include "SGFXTypes.h"
#include "Shader.h"
#include "Renderer.h"
#include "BMPTextures.h"

class SGFXEngine
{
public:
	int _cursorPosX_;
	int _cursorPosY_;
	int _windowX_;
	int _windowY_;

	GLFWwindow* window;
	int Init(int windowX, int windowY, const char* title, GLFWmonitor* monitor=nullptr);
	SGFXEngine();
	~SGFXEngine();
	int x = 0;
private:
	void SetGLFWCallbacks();

	static void glfwErrorCallback(int errCode, const char* description);
	static void glfwKeyCallback(GLFWwindow* window, int keyCode, int scanCode, int action, int mods);
	static void glfwCursorPositionCallback(GLFWwindow* window, double xPos, double yPos);
	static void glfwMouseButtonCallback(GLFWwindow* window, int buttonCode, int action, int mods);
	static void glfwFrameBufferSizeCallback(GLFWwindow* window, int width, int height);
	static void glfwWindowPosCallback(GLFWwindow* window, int xpos, int ypos);

	void BindWindowToEngineContext();
};

namespace sgfxengine
{
	inline int cursorIsHeld = 0;
	inline int vertexId = 1;

	inline float PixelToVertex(int pixel, int screenDimention)
	{

		return ((float)pixel / screenDimention * 2) - 1.0f;
	}
}

