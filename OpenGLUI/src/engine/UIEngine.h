#pragma once
#define GLEW_STATIC
//#define _SUI_NO_DEBUG_


#include <GL/glew.h>
#include <GLFW/glfw3.h>


#ifndef _SUI_NO_DEBUG_
#define _BASIC_SHADER_DEBUG_
#endif

#define _MAX_BASIC_SHADER_SIZE_ 8192

#include "sLib.h"
#include "Shader.h"
#include "Renderer.h"

namespace uiengine
{
	inline int cursorIsHeld = 0;
	inline int vertexId = 1;

	inline float PixelToVertex(int pixel, int screenDimention)
	{

		return ((float)pixel / screenDimention*2)-1.0f;
	}
}

class UIEngine
{
public:
	int _cursorPosX_;
	int _cursorPosY_;
	int _windowX_;
	int _windowY_;

	GLFWwindow* window;
	int Init(int windowX, int windowY, const char* title, GLFWmonitor* monitor=nullptr);
	UIEngine();
	~UIEngine();
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

