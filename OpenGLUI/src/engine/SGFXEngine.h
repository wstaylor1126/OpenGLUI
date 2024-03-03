#if !defined(_SGFX_ENGINE_H_)
#define _SGFX_ENGINE_H_

//--Relevant SGFXEngine settings and macros

#if !defined(_SUI_NO_DEBUG_)
#define _SHOW_GL_CONTEXT_INFO_
#define _BASIC_SHADER_DEBUG_
#endif

#define _MAX_BASIC_SHADER_SIZE_ 8192


//--OpenGl related macros/settings

#define GLEW_STATIC
#define _GL_MAJOR_VERSION_ 3
#define _GL_MINOR_VERSION_ 3

#define _GL_USING_CORE_PROFILE_


//--Winapi
#include <windows.h>

//--Opengl bootstrapper and window context creation
#include <GL/glew.h>
#include <GLFW/glfw3.h>

//--C std lib, C++ std lib headers already includes this but I want to specify that I am in fact using C lib functions
#include <cstdlib>

//--The C++ std library
#include <iostream>
#include <string>
#include <fstream>
#include "sLib.h"

//--All SGFXEngine headers
#include "Error/SGFXError.h"
#include "Renderer/Shader.h"
#include "Renderer/Renderer.h"
#include "Renderer/Vertex/VertexArray.h"
#include "Renderer/Vertex/IndexBuffer.h"
#include "Renderer/Vertex/VertexBuffer.h"
#include "Renderer/Texture/BMPLoad.h"




namespace sgfxengine
{
	//--More temporary bullshit
	inline int cursorIsHeld = 0;
	inline int vertexId = 1;

	inline float PixelToVertex(int pixel, int screenDimention)
	{

		return ((float)pixel / screenDimention * 2) - 1.0f;
	}
}

class SGFXEngine
{
public:
	//--Most likely temporary containers for window information. Will be handled by something else later
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
	//--GLFW callbacks will later invoke custom SGFX callbacks in separate event handler
	//--These will do more "behind the scenes" stuff and serve as wrappers for the main SGFX callbacks
	void SetGLFWCallbacks();

	static void glfwErrorCallback(int errCode, const char* description);
	static void glfwKeyCallback(GLFWwindow* window, int keyCode, int scanCode, int action, int mods);
	static void glfwCursorPositionCallback(GLFWwindow* window, double xPos, double yPos);
	static void glfwMouseButtonCallback(GLFWwindow* window, int buttonCode, int action, int mods);
	static void glfwFrameBufferSizeCallback(GLFWwindow* window, int width, int height);
	static void glfwWindowPosCallback(GLFWwindow* window, int xpos, int ypos);

	void BindWindowToEngineContext();
};


#endif