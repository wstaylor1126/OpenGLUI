#include "UIEngine.h"


//--Callbacks
void UIEngine::glfwErrorCallback(int errCode, const char* description)
{
#ifndef _SUI_NO_DEBUG_
	std::cout << "GLFW error: " << errCode << ": " << description << std::endl;
#endif
}
void UIEngine::glfwKeyCallback(GLFWwindow* window, int keyCode, int scanCode, int action, int mods)
{
	UIEngine* engine = (UIEngine*)glfwGetWindowUserPointer(window);

	
	if (keyCode == GLFW_KEY_0 && action == GLFW_PRESS)
	{

	}
}
void UIEngine::glfwCursorPositionCallback(GLFWwindow* window, double xPos, double yPos)
{
	UIEngine* engine = (UIEngine*)glfwGetWindowUserPointer(window);
	if (xPos != 0 && yPos != 0)
	{
		engine->cursorPosX = xPos;
		engine->cursorPosY = yPos;
	}
}
void UIEngine::glfwMouseButtonCallback(GLFWwindow* window, int buttonCode, int action, int mods)
{
	UIEngine* engine = (UIEngine*)glfwGetWindowUserPointer(window);

	if (buttonCode == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
	{
		uiengine::cursorIsHeld = 1;
	}
	else if (buttonCode == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE)
	{
		uiengine::cursorIsHeld = 0;
	}
	
}


//--Public
UIEngine::UIEngine()
{

}
UIEngine::~UIEngine()
{

	glfwTerminate();
}
int UIEngine::Init(int windowX, int windowY, const char* title, GLFWmonitor* monitor)
{
	
	if (!glfwInit())
	{
#ifndef _SUI_NO_DEBUG_
		std::cout << "GLFW initialization failed." << std::endl;
#endif
		return 0;
	}

	window = glfwCreateWindow(windowX, windowY, title, monitor, nullptr);
	glfwMakeContextCurrent(window);

	BindWindowToEngineClass();

	GLenum errCode = glewInit();

	if (errCode)
	{
#ifndef _SUI_NO_DEBUG_
		const char* glewErrStr = (char*)glewGetErrorString(errCode);
		std::cout << "GLEW error: " << glewErrStr << std::endl;
#endif
		return 0;
	}

	SetGLFWCallbacks();

	return 1;
}
//--Private
void UIEngine::SetGLFWCallbacks()
{
	glfwSetErrorCallback((GLFWerrorfun)glfwErrorCallback);
	glfwSetKeyCallback(window, (GLFWkeyfun)glfwKeyCallback);
	glfwSetCursorPosCallback(window, (GLFWcursorposfun)glfwCursorPositionCallback);
	glfwSetMouseButtonCallback(window, (GLFWmousebuttonfun)glfwMouseButtonCallback);

}
void UIEngine::BindWindowToEngineClass()
{
	glfwSetWindowUserPointer(window, this);
}



